#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../include/CLI11.hpp"

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    std::cout << "Vision CLI is running!" << std::endl;
    bool gray;
    CLI::App app{"Vision CLI"};
    std::string image_path;
    app.add_option("-i,--image", image_path, "Path to the image file")
       ->required()
       ->check(CLI::ExistingFile);
    app.add_flag("-g,--gray", gray, "Convert image to grayscale");

    CLI11_PARSE(app, argc, argv);

    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
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
    if (gray) {
        cv::namedWindow("Display Grayscale Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display Grayscale Image", img);
    } else {
        cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display Image", img);
    }
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
