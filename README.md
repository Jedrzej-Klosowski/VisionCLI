# VisionCLI – Terminal-Based Object Recognition on Images

**VisionCLI** is a C++ command-line tool for analyzing and processing images directly from the terminal. It uses OpenCV for object detection with YOLOv3, grayscale conversion, and image display functionality.

---

## ✨ Features

- **Object detection** using YOLOv3 neural network (detects 80 COCO object classes)
- **Grayscale conversion** with automatic saving of processed images
- **Image display** in OpenCV window (color or grayscale)
- **CLI interface** powered by [CLI11](https://github.com/CLIUtils/CLI11)
- **Flexible YOLO model paths** - use default or specify custom cfg/weights files
- **Pre-configured YOLO models** - all required files included in repository

---

## 🚀 Quick Start

### Requirements

- **C++20** compiler (MSVC, GCC, or Clang)
- **[OpenCV](https://opencv.org/)** >= 4.0
- **CMake** >= 3.10
- **Windows** (uses Windows API - `windows.h`)

### Installation

#### 1. Install OpenCV

**Windows:**
```bash
# Download OpenCV from https://opencv.org/releases/
# Extract to C:/opencv (or update CMakeLists.txt with your path)
```

**Important:** Update the OpenCV path in `CMakeLists.txt` line 6 to match your installation:
```cmake
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
```

#### 2. Clone the Repository

```bash
git clone https://github.com/Jedrzej-Klosowski/VisionCLI.git
cd VisionCLI
```

**All YOLO model files are included** - no additional downloads needed!  ✅

#### 3. Build the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .  --config Release
```

---

## 📖 Usage

### Basic Commands

```bash
# Object detection with display
./VisionCLI --image ../assets/dog.jpg --run --show

# Convert to grayscale
./VisionCLI --image ../assets/dog.jpg --gray --show

# Use custom YOLO model
./VisionCLI --image photo.jpg --run --cfg path/to/custom.cfg --weights path/to/custom.weights

# Just display image
./VisionCLI --image photo.jpg --show
```

### Command-Line Arguments

| Argument | Short | Description | Required |
|----------|-------|-------------|----------|
| `--image <file>` | `-i` | Path to input image file | **Yes** |
| `--run` | `-r` | Run YOLOv3 object detection | No |
| `--gray` | `-g` | Convert to grayscale and save copy | No |
| `--show` | `-s` | Display image in window | No |
| `--cfg <file>` | | Custom path to yolov3.cfg (default: include/yolov3.cfg) | No |
| `--weights <file>` | | Custom path to yolov3.weights (default: include/yolov3.weights) | No |

**Note:** Using `--run` automatically enables `--show`

---

## 📁 Project Structure

```
VisionCLI/
├── src/
│   └── main.cpp              # Main application source code
├── include/
│   ├── CLI11.hpp             # CLI argument parser library
│   ├── coco.names            # COCO dataset class names (80 objects)
│   ├── yolov3.cfg            # YOLOv3 neural network configuration
│   └── yolov3.weights        # YOLOv3 pre-trained weights (~248 MB)
├── assets/                   # Sample images for testing
├── CMakeLists.txt            # CMake build configuration
├── NOTES.md                  # Development notes and roadmap
├── README.md                 # This file
└── . gitignore                # Git ignore rules
```

---

## 🎯 Object Detection Details

VisionCLI can detect **80 different object classes** from the COCO dataset:

**Categories include:**
- **People & Animals:** person, dog, cat, horse, bird, cow, elephant, bear, zebra, giraffe
- **Vehicles:** car, bicycle, motorcycle, bus, train, truck, boat, airplane
- **Indoor Objects:** chair, sofa, bed, dining table, toilet, TV, laptop, mouse, keyboard
- **Food & Kitchen:** bottle, cup, fork, knife, spoon, bowl, banana, apple, sandwich, pizza, donut
- **Sports:** sports ball, kite, baseball bat, skateboard, surfboard, tennis racket
- And more...

**Detection Parameters:**
- Confidence threshold: 50%
- NMS threshold: 0.4 (Non-Maximum Suppression)
- Input size: 416×416 pixels
- Backend: OpenCV DNN (CPU)

---

## 📊 Output

### Grayscale Conversion
When using `--gray`, creates a copy with suffix `-szara-kopia`:
```
Input:   assets/dog.jpg
Output: assets/dog-szara-kopia.jpg
```

### Object Detection
Detected objects are shown with:
- Green bounding boxes
- Class name labels above boxes
- Displayed in OpenCV window

---

## 🛠️ Technologies

- **C++20** (with C++17 filesystem support)
- **OpenCV 4.x** - Computer vision and image processing
- **CMake** - Cross-platform build system
- **CLI11** - Modern command-line argument parsing
- **YOLOv3** - Real-time object detection neural network

---

## ⚠️ System Requirements & Limitations

**Requirements:**
- Windows 10/11 (64-bit)
- ~500 MB disk space (includes YOLO weights)
- 4GB+ RAM recommended for object detection

**Current Limitations:**
- **Windows-only** - Uses Windows API (`windows.h`) for path resolution
- **CPU-only** - No GPU acceleration (processing may be slow on large images)
- **Hardcoded paths** - OpenCV path in CMakeLists.txt must be manually updated

---

## 🐛 Troubleshooting

### Build Issues

**"CMake could not find OpenCV"**
```cmake
# Update CMakeLists.txt line 6 with your OpenCV path: 
set(OpenCV_DIR "YOUR_PATH/opencv/build/x64/vc16/lib")
```

### Runtime Issues

**"Missing weights file: ..."**
- Verify that `include/yolov3.weights` exists in your cloned repository
- File should be approximately 248 MB
- If missing, re-clone the repository or check if the file was excluded by . gitignore

**"Could not open coco.names!"**
- Run the program from the `build/` directory
- Check that `../include/coco.names` exists relative to executable

**"Could not open or find the image!"**
- Verify image path is correct (use absolute path or path relative to executable)
- Supported formats: JPG, PNG, BMP, TIFF

**Slow detection speed**
- YOLOv3 on CPU is computationally intensive
- Expected:  2-5 seconds per image on modern CPUs
- Consider using smaller images or YOLOv3-tiny for faster processing

---

## 🤝 Contributing

Contributions are welcome! Here's how:

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/amazing-feature`
3. Make your changes and test thoroughly
4. Commit with clear messages: `git commit -m 'Add amazing feature'`
5. Push to your fork: `git push origin feature/amazing-feature`
6. Open a Pull Request

**Please ensure:**
- Code follows existing style
- Comments are in English
- No warnings during compilation

---

## 📃 License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2026 Jędrzej Kłosowski

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. 
```

---

## ✉️ Contact & Links

**Author:** Jędrzej Kłosowski  
**GitHub:** [@Jedrzej-Klosowski](https://github.com/Jedrzej-Klosowski)  
**Repository:** [VisionCLI](https://github.com/Jedrzej-Klosowski/VisionCLI)

**Resources:**
- [OpenCV Documentation](https://docs.opencv.org/)
- [YOLOv3 Paper](https://arxiv.org/abs/1804.02767)
- [COCO Dataset](https://cocodataset.org/)
- [CLI11 Library](https://github.com/CLIUtils/CLI11)

---

**VisionCLI** – Powerful computer vision directly from your terminal!  🔍✨