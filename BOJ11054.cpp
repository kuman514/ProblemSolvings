#include <iostream>
#include <vector>

// Solving BOJ 11054

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    std::cin >> n;
    
    std::vector<int> values;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        values.push_back(input);
    }
    
    // Get longest increasing
    std::vector<int> longestInc;
    for (int i = 0; i < n; i++) {
        int curLong = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (values[i] > values[j] && curLong < longestInc[j]) {
                curLong = longestInc[j];
            }
        }
        longestInc.push_back(curLong + 1);
    }
    
    /*
    // Debug
    for (int i = 0; i < n; i++) {
        std::cout << longestInc[i] << ' ';
    }
    std::cout << '\n';
    */
    
    // Get longest decreasing
    std::vector<int> longestDec(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        int curLong = 0;
        for (int j = i + 1; j < n; j++) {
            if (values[i] > values[j] && curLong < longestDec[j]) {
                curLong = longestDec[j];
            }
        }
        longestDec[i] = curLong + 1;
    }
    
    /*
    // Debug
    for (int i = 0; i < n; i++) {
        std::cout << longestDec[i] << ' ';
    }
    std::cout << '\n';
    */
    
    // Get longest bitonic
    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (longest < longestInc[i] + longestDec[i] - 1) {
            longest = longestInc[i] + longestDec[i] - 1;
        }
    }
    
    std::cout << longest << '\n';
    
    return 0;
}
