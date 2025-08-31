cmake_minimum_required(VERSION 3.10)
project(VisionCLI)

set(CMAKE_CXX_STANDARD 20)

# Ustaw ścieżkę do katalogu, gdzie znajduje się OpenCVConfig.cmake
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(OpenCV REQUIRED)

add_executable(VisionCLI main.cpp)

target_include_directories(VisionCLI PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(VisionCLI PRIVATE ${OpenCV_LIBS})
