//
// Created by loooph on 19.05.2018.
//

#ifndef SORTIERALGORITHMEN_SHELLSORT_HPP
#define SORTIERALGORITHMEN_SHELLSORT_HPP

#include <vector>
#include <cstdlib>

/**
 * @brief Sortierung eines Feldes mittels Shellsort-Algorithmus
 * @param A zu sortierendes Feld
 * @post A ist sortiert
 */
void shellsort(std::vector<int> &A);

/**
 * @brief Sortierung eines Feldes mittels Shellsort-Algorithmus mit vorgegebenen Schrittweiten
 * @param A zu sortierendes Feld
 * @param schrittweiten Feld welches die Schrittweiten in absteigender Größe enthält
 * @post A ist sortiert
 */
void shellsort(std::vector<int> &A, const std::vector<size_t> &schrittweiten);

/**
 * @brief Sortierung eines Feldes mittels Shellsort-Algorithmus\n
 * Zählt Schlüsselvergleiche und Schreibzugriffe im Feld
 * @param A zu sortierendes Feld
 * @param vergleiche Zählvariable für Vergleiche von Elementen in A
 * @param schreibzugriffe Zählvariable für Schreibzugriffe auf A
 * @post A ist sortiert
 * @post Änderung von vergleiche
 * @post Änderung von schreibzugriffe
 */
void shellsort(std::vector<int> &A, unsigned int& vergleiche, unsigned int& schreibzugriffe);

/**
 * @brief Sortierung eines Feldes mittels Shellsort-Algorithmus\n
 * Zählt Schlüsselvergleiche und Schreibzugriffe im Feld
 * @param A zu sortierendes Feld
 * @param schrittweiten Feld welches die Schrittweiten in absteigender Größe enthält
 * @param vergleiche Zählvariable für Vergleiche von Elementen in A
 * @param schreibzugriffe Zählvariable für Schreibzugriffe auf A
 * @post A ist sortiert
 * @post Änderung von vergleiche
 * @post Änderung von schreibzugriffe
 */
void shellsort(std::vector<int> &A, const std::vector<size_t> &schrittweiten, unsigned int &vergleiche,
               unsigned int &schreibzugriffe);

void shellsort(std::vector<int> &A) {
    size_t schrittweite = 0;
    while (3 * schrittweite + 1 < A.size()) {
        schrittweite = 3 * schrittweite + 1;
    }
    while (schrittweite > 0) {
        for (size_t i = schrittweite; i < A.size(); ++i) {
            int neu = A.at(i);
            size_t k = i;
            while (k >= schrittweite && A.at(k - schrittweite) > neu) {
                A.at(k) = A.at(k - schrittweite);
                k -= schrittweite;
            }
            A.at(k) = neu;
        }
        schrittweite /= 3;
    }
}

void shellsort(std::vector<int> &A, const std::vector<size_t> &schrittweiten) {
    size_t s = 0;
    while (s < schrittweiten.size()) {
        for (size_t i = schrittweiten.at(s); i < A.size(); ++i) {
            int neu = A.at(i);
            size_t k = i;
            while (k >= schrittweiten.at(s) && A.at(k - schrittweiten.at(s)) > neu) {
                A.at(k) = A.at(k - schrittweiten.at(s));
                k -= schrittweiten.at(s);
            }
            A.at(k) = neu;
        }
        s++;
    }
}

void shellsort(std::vector<int> &A, unsigned int &vergleiche, unsigned int &schreibzugriffe) {
    size_t schrittweite = 0;
    while (3 * schrittweite + 1 < A.size()) {
        schrittweite = 3 * schrittweite + 1;
    }
    while (schrittweite > 0) {
        for (size_t i = schrittweite; i < A.size(); ++i) {
            int neu = A.at(i);
            size_t k = i;
            while (k >= schrittweite && (++vergleiche, A.at(k - schrittweite) > neu)) {
                ++schreibzugriffe;
                A.at(k) = A.at(k - schrittweite);
                k -= schrittweite;
            }
            ++schreibzugriffe;
            A.at(k) = neu;
        }
        schrittweite /= 3;
    }
}

void shellsort(std::vector<int> &A, const std::vector<size_t> &schrittweiten, unsigned int &vergleiche,
               unsigned int &schreibzugriffe) {
    size_t s = 0;
    while (s < schrittweiten.size()) {
        for (size_t i = schrittweiten.at(s); i < A.size(); ++i) {
            int neu = A.at(i);
            size_t k = i;
            while (k >= schrittweiten.at(s) && (++vergleiche, A.at(k - schrittweiten.at(s)) > neu)) {
                ++schreibzugriffe;
                A.at(k) = A.at(k - schrittweiten.at(s));
                k -= schrittweiten.at(s);
            }
            ++schreibzugriffe;
            A.at(k) = neu;
        }
        s++;
    }
}

#endif //SORTIERALGORITHMEN_SHELLSORT_HPP
