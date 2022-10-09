#include <iostream>
#include <vector>

// Solving BOJ 2491

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    int maxLen = 0;
    int curLen = 1;

    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i - 1] > nums[i]) {
            curLen = 1;
        } else {
            curLen++;
        }
        
        maxLen = std::max(maxLen, curLen);
    }
    
    curLen = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i - 1] < nums[i]) {
            curLen = 1;
        } else {
            curLen++;
        }
        
        maxLen = std::max(maxLen, curLen);
    }
    
    std::cout << maxLen << '\n';

    return 0;
}
