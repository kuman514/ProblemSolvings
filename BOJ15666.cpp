#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 15666

void pickPermutation(int depth, int curIndex, int maxDepth, std::vector<int> &nums, std::vector<int> &curContain) {
    for (int i = curIndex; i < nums.size(); i++) {
        curContain.push_back(nums[i]);
        if (depth == maxDepth) {
            for (int j = 0; j < curContain.size(); j++) {
                std::cout << curContain[j];
                if (j == curContain.size() - 1) {
                    std::cout << '\n';
                } else {
                    std::cout << ' ';
                }
            }
        } else {
            pickPermutation(depth + 1, i, maxDepth, nums, curContain);
        }
        curContain.pop_back();
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m;
    std::cin >> n >> m;
    
    std::vector<bool> exsits(10001, false);
    std::vector<int> nums;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        
        if (!exsits[input]) {
            nums.push_back(input);
            exsits[input] = true;
        }
    }
    
    // Sort required
    std::sort(nums.begin(), nums.end());
    
    // Backtracking solution
    std::vector<int> curContain;
    pickPermutation(0, 0, m - 1, nums, curContain);

    return 0;
}
