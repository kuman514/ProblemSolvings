#include <iostream>

// Solving BOJ 21612

int main(void) {
    int b;
    std::cin >> b;
    
    int p = 5 * b - 400;
    
    std::cout << p << '\n';
    
    if (p > 100) {
        std::cout << (-1);
    } else if (p < 100) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
    
    std::cout << '\n';

    return 0;
}
