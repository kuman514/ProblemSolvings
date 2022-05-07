#include <iostream>

// Solving BOJ 18005

int main(void) {
    long long n;
    std::cin >> n;
    
    if (n % 2LL == 1LL) {
        std::cout << 0;
    } else if ((n / 2LL) % 2LL == 1LL) {
        std::cout << 1;
    } else if ((n / 2LL) % 2LL == 0LL) {
        std::cout << 2;
    }
    
    std::cout << '\n';

    return 0;
}
