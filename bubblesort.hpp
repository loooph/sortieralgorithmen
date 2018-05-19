//
// Created by loooph on 19.05.2018.
//

#ifndef SORTIERALGORITHMEN_BUBBLESORT_HPP
#define SORTIERALGORITHMEN_BUBBLESORT_HPP

#include <vector>
#include <cstdlib>
#include "util.hpp"

/**
 * @brief Sortierung eines Feldes mittels Bubblesort-Algorithmus\n
 * Zählt Schlüsselvergleiche und Schreibzugriffe im Feld
 * @param A zu sortierendes Feld
 * @post A ist sortiert
 */
void bubblesort(std::vector& A);

/**
 * @brief Sortierung eines Feldes mittels Bubblesort-Algorithmus\n
 * Zählt Schlüsselvergleiche und Schreibzugriffe im Feld
 * @param A zu sortierendes Feld
 * @param vergleiche Zählvariable für Vergleiche von Elementen in A
 * @param schreibzugriffe Zählvariable für Schreibzugriffe auf A
 * @post A ist sortiert
 * @post Änderung von vergleiche
 * @post Änderung von schreibzugriffe
 */
void bubblesort(std::vector& A, unsigned int& vergleiche, unsigned int& schreibzugriffe);



void bubblesort(std::vector &A) {
    bool warSortiert;
    do {
        warSortiert = true;
        for(size_t i = 0; i < A.size() - 1; ++i) {
            if (A.at(i) > A.at(i + 1)) {
                warSortiert = false;
                vertausche(A, i, i+1);
            }
        }
    } while (!warSortiert);
}

void bubblesort(std::vector &A, unsigned int &vergleiche, unsigned int &schreibzugriffe) {
    bool warSortiert;
    do {
        warSortiert = true;
        for(size_t i = 0; i < A.size() - 1; ++i) {
            if ((++vergleiche, A.at(i) > A.at(i + 1))) {
                warSortiert = false;
                schreibzugriffe += 2;
                vertausche(A, i, i+1);
            }
        }
    } while (!warSortiert);
}

#endif //SORTIERALGORITHMEN_BUBBLESORT_HPP
