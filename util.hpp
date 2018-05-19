//
// Created by loooph on 20.05.2018.
//

#ifndef SORTIERALGORITHMEN_UTIL_HPP
#define SORTIERALGORITHMEN_UTIL_HPP

#include <vector>
#include <cstdlib>

/**
 * @brief Vertauscht 2 Elemente in einem Feld
 * @param A Feld in dem 2 Elemente vertauscht werden
 * @param i Index des ersten Elements
 * @param j Index des zweiten Elements
 * @post Änderung in A
 */
void vertausche(std::vector<int>& A, size_t i, size_t j);

void vertausche(std::vector<int> &A, size_t i, size_t j) {
    int tmp = A.at(i);
    A.at(i) = A.at(j);
    A.at(j) = tmp;
}

#endif //SORTIERALGORITHMEN_UTIL_HPP
