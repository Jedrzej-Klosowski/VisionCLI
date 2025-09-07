#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <../include/CLI11.hpp>

#include <iostream>

int main() {
    std::cout << "Vision CLI is running!" << std::endl;
    cv::Mat img = cv::imread(R"(../assets/dog.jpg)", cv::IMREAD_COLOR);
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