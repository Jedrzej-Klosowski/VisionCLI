# VisionCLI – Terminal-Based Image Recognizer

**VisionCLI** is a C++ tool for analyzing images directly from the terminal. It utilizes OpenCV for object detection (YOLOv3), grayscale conversion, and basic image display functionalities.

---

## ✨ Features

- **Object detection** on images using YOLOv3 (requires `yolov3.cfg`, `yolov3.weights`, and `coco.names` files in the `include/` directory).
- **Image conversion to grayscale** and saving a copy.
- **Image display** (color or grayscale) in an OpenCV window.
- Simple and intuitive CLI interface (based on [CLI11](https://github.com/CLIUtils/CLI11)).
- Easy to configure and extend.

---

## 🚀 Quick Start

### Requirements

- C++20 (minimum C++17)
- [OpenCV](https://opencv.org/) (>= 4.0)
- CMake (>= 3.10)
- YOLO model files (place in `include/`):  
  - `yolov3.cfg`  
  - `yolov3.weights`  
  - `coco.names`

### Building the Project

```bash
git clone https://github.com/Jedrzej-Klosowski/VisionCLI.git
cd VisionCLI
mkdir build && cd build
cmake ..
make
```

### Example Usage

```bash
./VisionCLI --image assets/dog.jpg --run --show
```

#### Available Arguments

- `-i, --image <file>` — path to the image file (**required**)
- `-g, --gray` — converts the image to grayscale and saves a copy
- `-s, --show` — displays the image in a window
- `-r, --run` — runs object detection on the image (YOLOv3)

---

## 📁 Project Structure

```
VisionCLI/
├── src/              # Source code (main.cpp)
├── include/          # Header files, YOLO models, coco.names
├── assets/           # Sample images
├── CMakeLists.txt    # Build configuration
├── README.md         # Project documentation
├── LICENSE           # MIT License
├── .gitignore        # Git ignored files
```

---

## 🛠️ Technologies

- **C++20** (also works with C++17)
- **OpenCV**
- **CMake**
- **CLI11** (for CLI argument handling)
- (optional) YOLOv3 and configuration files

---

## 🤝 Contributions

1. Fork the repository
2. Create a new branch (`git checkout -b feature/name`)
3. Apply changes and write tests
4. Submit a pull request

---

## 📃 License

This project is licensed under the MIT License – feel free to use, modify, and distribute it!

---

## ✉️ Contact

Author: [Jędrzej Kłosowski](https://github.com/Jedrzej-Klosowski)

---

**VisionCLI** – Explore the world directly from the terminal!

---

[View this README in Polish](https://github.com/Jedrzej-Klosowski/VisionCLI/blob/main/README.md)
