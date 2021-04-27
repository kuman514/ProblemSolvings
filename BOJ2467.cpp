#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 2467

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    std::cin >> n;
    std::vector<int> ph;
    
    // Get input
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        ph.push_back(input);
    }
    
    std::sort(ph.begin(), ph.end());
    
    // Two pointer solution
    int left = 0;
    int right = static_cast<int>(ph.size()) - 1;
    int minDiff = 2000000001;
    int minDiffL = -1;
    int minDiffR = -1;
    
    while (left < right) {
        int curDiff = ph[left] + ph[right];
        if (minDiff > std::abs(curDiff)) {
            minDiff = std::abs(curDiff);
            minDiffL = left;
            minDiffR = right;
        }
        
        if (curDiff > 0) {
            right--;
        } else if (curDiff < 0) {
            left++;
        } else {
            break;
        }
    }
    
    std::cout << ph[minDiffL] << ' ' << ph[minDiffR] << '\n';
    
    return 0;
}
