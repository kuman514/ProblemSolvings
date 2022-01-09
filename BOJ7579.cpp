#include <iostream>
#include <vector>
#include <utility>

// Solving BOJ 7579

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    // first: memory, second: cost
    std::vector< std::pair<int, int> > apps(n, std::pair<int, int>());
    
    // Get memory
    for (int i = 0; i < n; i++) {
        std::cin >> apps[i].first;
    }
    
    // Get cost
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> apps[i].second;
        totalCost += apps[i].second;
    }
    
    // Knapsack DP
    std::vector<int> largestMemory(totalCost + 1, 0);
    for (int i = 0; i < apps.size(); i++) {
        const int currentMemory = apps[i].first;
        const int currentCost = apps[i].second;
        
        for (int j = totalCost; j >= currentCost; j--) {
            const int memoryIfYouErase = largestMemory[j - currentCost] + currentMemory;
            if (largestMemory[j] < memoryIfYouErase) {
                largestMemory[j] = memoryIfYouErase;
            }
        }
    }
    
    // Print the lowest cost to get m memory
    for (int i = totalCost; i >= 0; i--) {
        if (largestMemory[i] < m) {
            std::cout << (i + 1) << '\n';
            break;
        }
    }

    return 0;
}
