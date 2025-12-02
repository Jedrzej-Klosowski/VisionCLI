#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include "../include/CLI11.hpp"
#include <windows.h>

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using namespace cv;
using namespace dnn;
using namespace std;
int main(int argc, char* argv[]) {
    std::cout << "Vision CLI is running!" << std::endl;
    bool gray = false;
    bool show = false;
    bool run = false;

    CLI::App app{"Vision CLI"};
    std::string image_path;
    app.add_option("-i,--image", image_path, "Path to the image file")
       ->required()
       ->check(CLI::ExistingFile);
    app.add_flag("-g,--gray", gray, "Convert image to grayscale");
    app.add_flag("-s,--show", show, "Display the image in a window");
    app.add_flag("-r,--run", run,"Run object detection on the image");

    CLI11_PARSE(app, argc, argv);

    // Diagnostic logs
    cout << "Args: image=" << image_path << " show=" << show << " gray=" << gray << " run=" << run << endl;

    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cout << "Loaded image: " << img.cols << "x" << img.rows << " channels=" << img.channels() << endl;

    if (run) {
        show = true;
        // Pobierz ścieżkę do katalogu z plikiem wykonywalnym
        char exePath[MAX_PATH];
        GetModuleFileNameA(NULL, exePath, MAX_PATH);
        fs::path exeDir = fs::path(exePath).parent_path();
        fs::path cocoPath = exeDir / ".." / "include" / "coco.names";
        ifstream ifs(cocoPath);
        if (!ifs.is_open()) {
            cerr << "Could not open coco.names!" << endl;
            return -1;
        }
        vector<string> classes;
        string line;
        while (getline(ifs, line)) classes.push_back(line);
        if (classes.empty()) {
            cerr << "No class names loaded!" << endl;
            return -1;
        }
        Net net = readNetFromDarknet((exeDir / ".." / "include" / "yolov3.cfg").string(), (exeDir / ".." / "include" / "yolov3.weights").string());
        net.setPreferableBackend(DNN_BACKEND_OPENCV);
        net.setPreferableTarget(DNN_TARGET_CPU);
        Mat blob = blobFromImage(img, 1.0f/255.0f, Size(416, 416), Scalar(0,0,0), true, false);
        net.setInput(blob);
        vector<String> outNames = net.getUnconnectedOutLayersNames();
        vector<Mat> outs;
        net.forward(outs, outNames);
        float confThreshold = 0.5f;
        float nmsThreshold = 0.4f;
        vector<Rect> boxes;
        vector<int> classIds;
        vector<float> confidences;
        for (auto &out : outs) {
            auto data = reinterpret_cast<float*>(out.data);
            for (int i = 0; i < out.rows; i++, data += out.cols) {
                Mat scores = out.row(i).colRange(5, out.cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, nullptr, &confidence, nullptr, &classIdPoint);
                if (confidence > confThreshold) {
                    int centerX = static_cast<int>(data[0] * img.cols);
                    int centerY = static_cast<int>(data[1] * img.rows);
                    int width   = static_cast<int>(data[2] * img.cols);
                    int height  = static_cast<int>(data[3] * img.rows);
                    int left    = centerX - width / 2;
                    int top     = centerY - height / 2;

                    boxes.emplace_back(left, top, width, height);
                    classIds.push_back(classIdPoint.x);
                    confidences.push_back(static_cast<float>(confidence));
                }
            }
        }

        // Non-Maximum Suppression
        vector<int> indices;
        cv::dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

        for (int idx : indices) {
            Rect box = boxes[idx];
            rectangle(img, box, Scalar(0,255,0), 2);
            if (classIds[idx] >= 0 && classIds[idx] < classes.size()) {
                putText(img, classes[classIds[idx]], Point(box.x, box.y - 10),
                        FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,0), 2);
            } else {
                cerr << "classId out of range: " << classIds[idx] << endl;
            }
        }
    }
    if (gray) {
        cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

        fs::path input_path(image_path);
        fs::path output_path = input_path.parent_path() /          // katalog wejściowy (../assets)
                               (input_path.stem().string() +       // nazwa pliku (dog)
                                "-szara-kopia" +                   // suffix
                                input_path.extension().string());  // rozszerzenie (.jpg)

        cv::imwrite(output_path.string(), img);

        std::cout << "Saved grayscale image as: " << output_path << std::endl;
    }
    if (show && gray) {
        cv::namedWindow("Display Grayscale Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display Grayscale Image", img);
    } else if (show && !gray) {
        cv::namedWindow("Display Color Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display Color Image", img);
    } else {
        return 0;
    }


    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
