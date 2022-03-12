#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Solving BOJ 18110

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::vector<int> opinion;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        opinion.push_back(input);
    }
    
    std::sort(opinion.begin(), opinion.end());
    
    int sideExceptCnt = static_cast<int>(std::round(n * 0.15));
    int totalOpinion = 0;
    for (int i = sideExceptCnt; i < n - sideExceptCnt; i++) {
        totalOpinion += opinion[i];
    }
    
    double rawAverage = (n - 2 * sideExceptCnt > 0) ? static_cast<double>(totalOpinion) / (n - 2 * sideExceptCnt) : 0.0;
    int finalAverage = std::round(rawAverage);
    
    std::cout << finalAverage << '\n';
    
    return 0;
}
