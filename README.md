````markdown name=README.md
# VisionCLI – Terminalowy Rozpoznawacz Obrazów w Terminalu

**VisionCLI** to narzędzie w C++ umożliwiające analizę obrazów z poziomu terminala. Wykorzystuje OpenCV do detekcji obiektów (YOLOv3), konwersji do odcieni szarości oraz podstawowego wyświetlania obrazów. Kod jest prosty, nowoczesny i łatwy do rozbudowy o kolejne funkcjonalności.

---

## ✨ Funkcje

- **Detekcja obiektów** na obrazie przy pomocy YOLOv3 (wymaga plików `yolov3.cfg`, `yolov3.weights` oraz `coco.names` w katalogu `include/`).
- **Konwersja obrazu do odcieni szarości** i zapis kopii.
- **Wyświetlanie obrazu** (kolorowego lub szarego) w oknie OpenCV.
- Prosty i przejrzysty interfejs CLI (oparty o [CLI11](https://github.com/CLIUtils/CLI11)).
- Łatwa konfiguracja oraz dalsza rozbudowa.

---

## 🚀 Szybki start

### Wymagania

- C++20 (minimalnie C++17)
- [OpenCV](https://opencv.org/) (>= 4.0)
- CMake (>= 3.10)
- Pliki modeli YOLO (umieść w `include/`):  
  - `yolov3.cfg`  
  - `yolov3.weights`  
  - `coco.names`

### Budowanie projektu

```bash
git clone https://github.com/Jedrzej-Klosowski/VisionCLI.git
cd VisionCLI
mkdir build && cd build
cmake ..
make
```

### Przykładowe użycie

```bash
./VisionCLI --image assets/dog.jpg --run --show
```

#### Dostępne argumenty

- `-i, --image <plik>` — ścieżka do pliku obrazu (**wymagane**)
- `-g, --gray` — konwertuje obraz do odcieni szarości i zapisuje kopię
- `-s, --show` — wyświetla obraz w oknie
- `-r, --run` — uruchamia detekcję obiektów na obrazie (YOLOv3)

---

## 📁 Struktura projektu

```
VisionCLI/
├── src/              # Kod źródłowy (main.cpp)
├── include/          # Pliki nagłówkowe, modele YOLO, coco.names
├── assets/           # Przykładowe obrazy
├── CMakeLists.txt    # Konfiguracja budowania
├── README.md         # Dokumentacja projektu
├── LICENSE           # Licencja MIT
├── .gitignore        # Pliki ignorowane przez git
```

---

## 🛠️ Technologie

- **C++20** (działa też z C++17)
- **OpenCV**
- **CMake**
- **CLI11** (do obsługi argumentów CLI)
- (opcjonalnie) YOLOv3 i pliki konfiguracyjne

---

## 🤝 Kontrybucje

1. Forkuj repozytorium
2. Stwórz nową gałąź (`git checkout -b feature/nazwa`)
3. Wprowadź zmiany i napisz testy
4. Zrób pull request

---

## 📃 Licencja

Projekt na licencji MIT – możesz używać, modyfikować i rozpowszechniać dowolnie!

---

## ✉️ Kontakt

Autor: [Jędrzej Kłosowski](https://github.com/Jedrzej-Klosowski)

---

**VisionCLI** – Rozpoznawaj świat prosto z terminala!
````
