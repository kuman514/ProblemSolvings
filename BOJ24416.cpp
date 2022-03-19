#include <iostream>
#include <vector>

// Solving BOJ 24416

int main(void) {
    int n;
    std::cin >> n;
    
    // Count that "return 1;" is called == n-th fibonacci value
    std::vector<int> fibo(n + 1, 0);
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    
    std::cout << fibo[n] << ' ' << (n - 2) << '\n';
    
    return 0;
}
