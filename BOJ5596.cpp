#include <iostream>

// Solving BOJ 5596

int main(void) {
    int a = 0;
    int b = 0;
    
    for (int i = 0; i < 4; i++) {
        int input;
        std::cin >> input;
        a += input;
    }
    
    for (int i = 0; i < 4; i++) {
        int input;
        std::cin >> input;
        b += input;
    }
    
    std::cout << std::max(a, b) << '\n';

    return 0;
}
