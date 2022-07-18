#include <iostream>

// Solving BOJ 10179

int main(void) {
    int n;
    std::cin >> n;
    
    std::cout.precision(2);
    std::cout << std::fixed;
    for (int i = 0; i < n; i++) {
        double input;
        std::cin >> input;
        std::cout << '$' << (0.8 * input) << '\n';
    }

    return 0;
}
