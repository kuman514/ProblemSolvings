#include <iostream>
#include <vector>
#include <cmath>

// Solving BOJ 1153

bool isPrime(int i) {
    int range = static_cast<int>(std::floor(std::sqrt(i)));
    bool isPrime = true;
    
    for (int j = 2; j <= range; j++) {
        if (i % j == 0) {
            isPrime = false;
            break;
        }
    }
    
    return isPrime;
}

int main(void) {
    // Get N
    int n;
    std::cin >> n;
    
    if (n < 8) {
        // There's no way to split into 4 primes if N < 8
        std::cout << (-1) << '\n';
    } else {
        std::vector<int> candidate(3, 0);
        if (n % 2 == 1) {
            candidate[0] = 2;
            candidate[1] = 3;
        } else {
            candidate[0] = 2;
            candidate[1] = 2;
        }
        
        bool seeking = true;
        for (int i = 2; i <= n && seeking; i++) {
            if (!isPrime(i)) {
                continue;
            }
            
            candidate[2] = i;
            
            int sum3 = candidate[0] + candidate[1] + candidate[2];
            int rest = n - sum3;
            
            if (rest > 1 && isPrime(rest)) {
                std::cout << candidate[0] << ' ' << candidate[1] << ' ' << candidate[2] << ' ' << rest << '\n';
                seeking = false;
            }
        }
    }

    return 0;
}
