#include <iostream>

// Solving BOJ 2010

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int input;
    int total = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        total += input;
    }
    
    std::cout << (total - (n - 1));

    return 0;
}
