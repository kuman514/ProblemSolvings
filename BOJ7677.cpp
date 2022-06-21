#include <iostream>

// Solving BOJ 7677

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // M: 10000 = 10 ** 4 -> K = 4
    // Cycle length: 15 * (10 ** (K - 1)) -> 15 * (10 ** 3) = 15000
    
    int fibo[15000] = {0, 1};
    for(int i = 2; i < 15000; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 10000;
    }
    
    int n;
    std::cin >> n;
    while (n != -1) {
        int reach = n % 15000;
        std::cout << fibo[reach] << '\n';
        std::cin >> n;
    }
    
    return 0;
}
