# VisionCLI – Terminalowy Rozpoznawacz Obiektów na Obrazach

**VisionCLI** to nowoczesna aplikacja w C++ umożliwiająca analizę obrazów bezpośrednio z poziomu terminala. Wykorzystuje bibliotekę OpenCV do wykrywania obiektów, kształtów i kolorów na zdjęciach, generując przejrzyste raporty oraz wizualizacje w stylu ASCII.

---

## ✨ Funkcje

- **Rozpoznawanie obiektów** (np. ludzi, zwierząt, pojazdów) na zdjęciach przy pomocy OpenCV i popularnych modeli (YOLO, Haar Cascades).
- **Wykrywanie kształtów** (koła, prostokąty, trójkąty) oraz dominujących kolorów.
- **Generowanie raportów** z analizy do pliku (JSON).
- **Podgląd wyników** w formie uproszczonego ASCII-art w terminalu.
- **Tryb batch** – analiza wielu obrazów naraz.
- **Obsługa własnych modeli** (np. niestandardowy YOLO).
- Prosty, przyjazny interfejs CLI.

---

## 🚀 Szybki start

### Wymagania

- C++17 lub nowszy
- [OpenCV](https://opencv.org/) (>= 4.0)
- CMake (>= 3.10)

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
./visioncli analyze assets/dog.jpg --shapes --colors --objects
```

#### Argumenty

- `analyze <plik>` — analiza obrazu
- `--shapes` — wykrywanie kształtów
- `--colors` — wykrywanie dominujących kolorów
- `--objects` — wykrywanie obiektów (ludzie, zwierzęta, pojazdy itd.)
- `--output <plik.json>` — zapis raportu do pliku
- `--ascii` — podgląd ASCII-art

---

## 📁 Struktura projektu

```
VisionCLI/
├── src/              # Kod źródłowy
├── include/          # Pliki nagłówkowe
├── tests/            # Testy
├── assets/           # Przykładowe obrazy
├── scripts/          # Skrypty pomocnicze
├── CMakeLists.txt    # Konfiguracja budowania
├── README.md         # Opis projektu
├── LICENSE           # Licencja
├── .gitignore        # Ignorowane pliki
```

---

## 🛠️ Technologie

- **C++17**
- **OpenCV**
- **CMake**
- (opcjonalnie) Catch2, YOLO/ONNX, fmtlib, nlohmann/json

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