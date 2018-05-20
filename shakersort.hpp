//
// Created by loooph on 20.05.2018.
//

#ifndef SORTIERALGORITHMEN_SHAKERSORT_HPP
#define SORTIERALGORITHMEN_SHAKERSORT_HPP

#include <vector>
#include <cstdlib>
#include "util.hpp"

/**
 * @brief Sortierung eines Feldes mittels Shakersort-Algorithmus\n
 * @param A zu sortierendes Feld
 * @post A ist sortiert
 */
void shakersort(std::vector<int>& A);

/**
 * @brief Sortierung eines Feldes mittels Shakersort-Algorithmus\n
 * Zählt Schlüsselvergleiche und Schreibzugriffe im Feld
 * @param A zu sortierendes Feld
 * @param vergleiche Zählvariable für Vergleiche von Elementen in A
 * @param schreibzugriffe Zählvariable für Schreibzugriffe auf A
 * @post A ist sortiert
 * @post Änderung von vergleiche
 * @post Änderung von schreibzugriffe
 */
void shakersort(std::vector<int>& A, unsigned int& vergleiche, unsigned int& schreibzugriffe);

void shakersort(std::vector<int>& A) {
    bool warSortiert;
    bool vor = true;
    size_t sortiert = 0;
    do {
        warSortiert = true;
        if (vor) {
            for(size_t i = 0; i < A.size() - 1 - sortiert; ++i) {
                if(A.at(i) > A.at(i + 1)) {
                    warSortiert = false;
                    vertausche(A, i, i + 1);
                }
            }
            vor = false;
        }
        else {
            for (size_t i = A.size() - 1; i > sortiert; --i ) {
                if(A.at(i - 1) > A.at(i)) {
                    warSortiert = false;
                    vertausche(A, i - 1, i);
                }
            }
            vor = true;
        }
        ++sortiert;
    } while (!warSortiert);
}


void shakersort(std::vector<int>& A, unsigned int& vergleiche, unsigned int& schreibzugriffe) {
    bool warSortiert;
    bool vor = true;
    size_t sortiert = 0;
    do {
        warSortiert = true;
        if (vor) {
            for(size_t i = 0; i < A.size() - 1 - sortiert; ++i) {
                if( ( ++vergleiche, A.at(i) > A.at(i + 1) ) ) {
                    warSortiert = false;
                    schreibzugriffe += 2;
                    vertausche(A, i, i + 1);
                }
            }
            vor = false;
        }
        else {
            for (size_t i = A.size() - 1; i > sortiert; --i ) {
                if( ( ++vergleiche, A.at(i - 1) > A.at(i) ) ) {
                    warSortiert = false;
                    schreibzugriffe += 2;
                    vertausche(A, i - 1, i);
                }
            }
            vor = true;
        }
        ++sortiert;
    } while (!warSortiert);
}

#endif //SORTIERALGORITHMEN_SHAKERSORT_HPP
