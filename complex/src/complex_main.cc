#include <iostream>
#include "complex.h"

int main(){
    std::cout << "\n- - - Complex2 Numbers class (overloaded operators and more) - - -" << std::endl;
    Complex complejo3(5, 3), complejo4(9, -8), complejo5(2, -6), complejo6(-8, 7);
    std::cout << ((complejo3) * (complejo4)) / ((complejo5) * (complejo6)) << std::endl;
    std::cout << complejo3 - complejo4 << std::endl;
    std::cout << complejo3 * complejo4 << std::endl;
    std::cout << complejo3 / complejo4 << std::endl;
    Complex cool_complejo;
    std::cin >> cool_complejo;
}