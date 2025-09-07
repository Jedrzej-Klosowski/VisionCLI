#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "../include/CLI11.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Vision CLI is running!" << std::endl;

    CLI::App app{"Vision CLI"};
    std::string image_path;
    app.add_option("-i,--image", image_path, "Path to the image file")
       ->required()
       ->check(CLI::ExistingFile);

    CLI11_PARSE(app, argc, argv);   // 🔥 to uruchamia parsowanie argumentów

    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
