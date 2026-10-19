# Checker – Porównywanie plików tekstowych
Opis projektu

Program napisany w języku C++, który wczytuje dane z pliku tekstowego, porównuje dwa zbiory tekstów i generuje raport zawierający elementy wspólne oraz elementy występujące tylko w jednym ze zbiorów.

Funkcjonalności

    Wczytywanie danych z pliku a.txt.
    Podział danych na dwa zbiory na podstawie słowa drugi.
    Wyszukiwanie elementów wspólnych dla obu zbiorów.
    Wyszukiwanie elementów występujących tylko w pierwszym zbiorze.
    Wyszukiwanie elementów występujących tylko w drugim zbiorze.
    Generowanie raportu w pliku raport.txt.

Dane w pliku a.txt powinny być zapisane w osobnych liniach. Słowo drugi oddziela pierwszy zbiór od drugiego.

Struktura programu

Program składa się z klasy checker, która zawiera trzy metody:

    wczytajDoPliku() – wczytuje dane z pliku i dzieli je na dwa wektory.
    check() – porównuje oba zbiory i wyszukuje elementy wspólne oraz różne.
    wypisz() – zapisuje wyniki porównania do pliku raport.txt.

Funkcja main() tworzy wektory, wywołuje metody klasy checker i uruchamia cały proces.
