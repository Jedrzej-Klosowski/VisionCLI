#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include "../include/CLI11.hpp"

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

    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }
    if (run) {
        vector<string> classes;
        ifstream ifs("coco.names");
        string line;
        while (getline(ifs, line)) classes.push_back(line);
        Net net = readNetFromDarknet("../include/yolov3.cfg", "../include/yolov3.weights");
        net.setPreferableBackend(DNN_BACKEND_OPENCV);
        net.setPreferableTarget(DNN_TARGET_CPU);
        Mat blob = blobFromImage(img, 1/255.0, Size(416, 416), Scalar(0,0,0), true, false);
        net.setInput(blob);
        vector<String> outNames = net.getUnconnectedOutLayersNames();
        vector<Mat> outs;
        net.forward(outs, outNames);

        float confThreshold = 0.5;

        // Przetwarzanie wyników
        for (auto &out : outs) {
            float* data = (float*)out.data;
            for (int i = 0; i < out.rows; i++, data += out.cols) {
                Mat scores = out.row(i).colRange(5, out.cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
                if (confidence > confThreshold) {
                    int centerX = (int)(data[0] * img.cols);
                    int centerY = (int)(data[1] * img.rows);
                    int width   = (int)(data[2] * img.cols);
                    int height  = (int)(data[3] * img.rows);
                    int left    = centerX - width / 2;
                    int top     = centerY - height / 2;

                    rectangle(img, Rect(left, top, width, height), Scalar(0,255,0), 2);
                    putText(img, classes[classIdPoint.x], Point(left, top - 10),
                            FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,0), 2);
                }
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
