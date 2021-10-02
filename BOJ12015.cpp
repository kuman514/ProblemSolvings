#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 12015

const int INIT = 0;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    std::cin >> n;
    
    // Using binary search on current result
    std::vector<int> result;
    result.push_back(INIT);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        
        if (result.back() < input) {
            result.push_back(input);
            answer++;
        } else {
            std::vector<int>::iterator pos = std::lower_bound(
                result.begin(),
                result.end(),
                input
            );
            
            *pos = input;
        }
    }
    
    // Print result
    std::cout << answer << '\n';
    
    return 0;
}
