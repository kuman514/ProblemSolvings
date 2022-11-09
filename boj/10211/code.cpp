#include <iostream>
#include <vector>

// Solving BOJ 10211

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int T;
    std::cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        std::cin >> n;
        
        std::vector<int> nums;
        for (int i = 0; i < n; i++) {
            int input;
            std::cin >> input;
            nums.push_back(input);
        }
        
        int maximumSubarray = -1000000007;
        for (int start = 0; start < n; start++) {
            int subarraySum = nums[start];
            maximumSubarray = std::max(maximumSubarray, subarraySum);
            
            for (int end = start + 1; end < n; end++) {
                subarraySum += nums[end];
                maximumSubarray = std::max(maximumSubarray, subarraySum);
            }
        }
        
        std::cout << maximumSubarray << '\n';
    }

    return 0;
}
