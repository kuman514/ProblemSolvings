#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 18411

int main(void) {
    std::vector<int> nums(3, -1);
    for (int i = 0; i < 3; i++) {
        std::cin >> nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    std::cout << (nums[1] + nums[2]) << '\n';

    return 0;
}
