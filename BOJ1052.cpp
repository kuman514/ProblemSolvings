#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// Solving BOJ 1052

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, k;
    std::cin >> n >> k;
    
    int answer = -1;
    for (int i = 0; i <= 10000000; i++) {
        int bottles = 0;
        int num = n + i;
        
        while (num > 0) {
            bottles += ((num % 2 == 1) ? 1 : 0);
            num >>= 1;
        }
        
        if (bottles <= k) {
            answer = i;
            break;
        }
    }
    
    std::cout << answer << '\n';
    
    return 0;
}
