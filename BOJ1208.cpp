#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 1208

void seekSum(int curSum, int start, std::vector<int>& nums, std::vector<int>& sums) {
    for (int i = start; i < nums.size(); i++) {
        int nextSum = curSum + nums[i];
        sums.push_back(nextSum);
        seekSum(nextSum, i + 1, nums, sums);
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get size
    int n, s;
    std::cin >> n >> s;
    
    // Split into 2 halves
    int size1 = n / 2;
    int size2 = n - size1;
    std::vector<int> nums1(size1, 0);
    std::vector<int> nums2(size2, 0);
    
    // Get numbers
    for (int i = 0; i < size1; i++) {
        std::cin >> nums1[i];
    }
    for (int i = 0; i < size2; i++) {
        std::cin >> nums2[i];
    }
    
    // Get half part sums
    std::vector<int> sums1;
    std::vector<int> sums2;
    seekSum(0, 0, nums1, sums1);
    seekSum(0, 0, nums2, sums2);
    
    std::sort(sums1.begin(), sums1.end());
    std::sort(sums2.begin(), sums2.end());
    
    long long count = 0LL;
    
    // Get the number of pairs in their own
    std::pair< std::vector<int>::iterator, std::vector<int>::iterator > result1 = std::equal_range(sums1.begin(), sums1.end(), s);
    std::pair< std::vector<int>::iterator, std::vector<int>::iterator > result2 = std::equal_range(sums2.begin(), sums2.end(), s);
    count += (result1.second - result1.first);
    count += (result2.second - result2.first);
    
    // Get the number of pairs across
    for (int i = 0; i < sums1.size(); i++) {
        std::pair< std::vector<int>::iterator, std::vector<int>::iterator > result = std::equal_range(sums2.begin(), sums2.end(), s - sums1[i]);
        count += (result.second - result.first);
    }
    
    std::cout << count << '\n';

    return 0;
}
