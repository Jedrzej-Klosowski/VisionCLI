# Plan działania – VisionCLI

## 1. Inicjalizacja projektu
- [x] Utwórz repozytorium i wrzuć README.md
- [x] Przygotuj środowisko (C++17+, CMake, OpenCV)

## 2. Struktura katalogów i plików
- [ ] Utwórz katalogi: `src/`, `include/`, `tests/`, `assets/`
- [ ] Dodaj plik `CMakeLists.txt` do głównego katalogu

## 3. Podstawowy szkielet aplikacji
- [ ] Napisz prosty `main.cpp` w `src/`, który wypisuje np. "VisionCLI start!"
- [ ] Dodaj funkcję ładowania obrazu z OpenCV (np. `cv::imread`)
- [ ] Przetestuj ładowanie przykładowego obrazu z katalogu `assets/`

## 4. Podstawowy interfejs CLI
- [ ] Dodaj obsługę argumentów wiersza poleceń (np. argc/argv lub biblioteką [CLI11](https://github.com/CLIUtils/CLI11))
- [ ] Pozwól uruchomić: `./visioncli analyze assets/example.jpg`

## 5. Pierwsza funkcja analizy obrazu
- [ ] Dodaj funkcję wykrywającą kształty (np. kontury, koła) na obrazie
- [ ] Wypisz wyniki analizy w terminalu

## 6. Raportowanie wyników
- [ ] Dodaj zapis wyników do pliku JSON (polecam bibliotekę [nlohmann/json](https://github.com/nlohmann/json))
- [ ] Dodaj opcję wywołania: `--output wynik.json`

## 7. Dalszy rozwój (kolejne iteracje)
- [ ] Dodaj wykrywanie obiektów (YOLO/Haar)
- [ ] Dodaj wykrywanie dominujących kolorów
- [ ] Dodaj tryb batch (przetwarzanie wielu plików)
- [ ] Dodaj ASCII-art jako podgląd

## 8. Testy, dokumentacja, automatyzacja
- [ ] Dodaj testy jednostkowe (np. z Catch2)
- [ ] Uzupełnij README.md o przykłady i zrzuty ekranu
- [ ] Dodaj workflow GitHub Actions (CI)

---

**Wskazówka:**  
Po każdym kroku commituj zmiany – łatwiej wrócić do działającego stanu!

**Masz pytania do któregoś z etapów? Chcesz gotowy szablon plików źródłowych lub CMakeLists.txt?**