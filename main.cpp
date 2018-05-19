#include <iostream>
#include <vector>
#include "shellsort.hpp"
#include "bubblesort.hpp"

int main() {
    unsigned int vgl = 0;
    unsigned int sz = 0;
    std::vector<int> A = {20, 54, 28, 31, 5, 24, 39, 14, 1, 15};
    for(const auto& a: A) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    bubblesort(A, vgl, sz);
    for(const auto& a: A) {
        std::cout << a << " ";
    }
    std::cout << std::endl << "Schreibzugriffe: " << sz << " Vergleiche: " << vgl << std::endl;

    vgl = 0;
    sz = 0;
    A = {20, 54, 28, 31, 5, 24, 39, 14, 1, 15};
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