cmake_minimum_required(VERSION 3.10)
project(VisionCLI)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(OpenCV REQUIRED)


add_executable(VisionCLI src/main.cpp)

target_include_directories(VisionCLI PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(VisionCLI PRIVATE ${OpenCV_LIBS})
