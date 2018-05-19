#include <iostream>
#include <vector>
#include "shellsort.hpp"

int main() {
    unsigned int vgl = 0;
    unsigned int sz = 0;
    std::vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for(const auto& a: A) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    shellsort(A, vgl, sz);
    for(const auto& a: A) {
        std::cout << a << " ";
    }
    std::cout << std::endl << "Schreibzugriffe: " << sz << " Vergleiche: " << vgl << std::endl;
    return 0;
}