#include <iostream>
#include <vector>

// Solving BOJ 11052

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get size
    int n;
    std::cin >> n;
    
    // Get each price to buy i card
    std::vector<int> cost(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> cost[i];
    }
    
    // Is cost[i - k] + cost[k] > cost[i]?
    for (int i = 2; i <= n; i++) {
        for (int k = i - 1; k >= 1; k--) {
            const int curSum = cost[k] + cost[i - k];
            if (cost[i] < curSum) {
                cost[i] = curSum;
            }
        }
    }
    
    std::cout << cost[n] << '\n';
    
    return 0;
}
