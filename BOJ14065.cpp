#include <iostream>
#include <iomanip>

// Solving BOJ 14065

int main(void) {
    double mi;
    std::cin >> mi;
    
    double litersPer100Km = 100 * 3.785411784 / (mi * 1.609344);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::cout << litersPer100Km << '\n';

    return 0;
}
