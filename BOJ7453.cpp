#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Sovling BOJ 7453

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector< std::vector<long long> > numbers(4, std::vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> numbers[j][i];
        }
    }
    
    // Split into 2 parts and get sums
    std::vector< std::vector<long long> > halfSums(2, std::vector<long long>());
    for (int part = 0; part < 2; part++) {
        int left = part * 2;
        int right = part * 2 + 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                halfSums[part].push_back(numbers[left][i] + numbers[right][j]);
            }
        }
    }
    
    // Sort halfSums to use Binary search
    std::sort(halfSums[1].begin(), halfSums[1].end());
    
    // Count pairs that sum[0,1][...] + sum[2,3][...] = 0
    long long count = 0;
    for (int i = 0; i < halfSums[0].size(); i++) {
        auto range = std::equal_range(
            halfSums[1].begin(),
            halfSums[1].end(),
            -halfSums[0][i]
        );
        
        count += std::distance(range.first, range.second);
    }
    
    std::cout << count << '\n';

    return 0;
}
