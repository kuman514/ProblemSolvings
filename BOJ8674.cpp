#include <iostream>

// Solving BOJ 8674

int main(void) {
    long long a, b;
    std::cin >> a >> b;
    
    if (a % 2LL == 0LL || b % 2LL == 0LL) {
        std::cout << 0;
    } else {
        std::cout << std::min(a, b);
    }
    
    std::cout << '\n';

    return 0;
}
