#include <iostream>
#include <vector>

// Solving BOJ 2293

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get sizes
    int n, k;
    std::cin >> n >> k;
    
    // Get coin values
    std::vector<int> coinValues;
    coinValues.push_back(0);
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        coinValues.push_back(input);
    }
    
    // Calculate total coin combinations
    std::vector<int> coinCombs(k + 1, 0);
    
    // Also making 0 by 0 counts as a combination
    coinCombs[0] = 1;
    
    // currentCoinCombs = prevComb[j] + currentCoinCombs[j - coinValues[i]]
    for (int i = 1; i <= n; i++) {
        for (int j = coinValues[i]; j <= k; j++) {
            //coinCombs[j] = coinCombs[j] + coinCombs[j - coinValues[i]];
            coinCombs[j] += coinCombs[j - coinValues[i]];
        }
    }
    
    std::cout << coinCombs[k] << '\n';

    return 0;
}
