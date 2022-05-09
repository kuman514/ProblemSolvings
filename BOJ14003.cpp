#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 14003

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    std::cin >> n;
    
    // Get numbers
    std::vector<int> array(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    
    // first: value, second: index of the value
    std::vector< std::pair<int, int> > increasing;
    
    // i-th number in <array> is index[i]-th number in <increasing>
    std::vector<int> index(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (increasing.size() == 0 || increasing.back().first < array[i]) {
            increasing.push_back({array[i], i});
            index[i] = increasing.size() - 1;
        } else {
            std::vector< std::pair<int, int> >::iterator pos = std::lower_bound(
                increasing.begin(),
                increasing.end(),
                std::pair<int, int>(array[i], 0),
                compare
            );
            int finalPos = pos - increasing.begin();
            
            increasing[finalPos] = std::pair<int, int>(array[i], i);
            index[i] = finalPos;
        }
    }
    
    // Get result searching in reverse
    int cur = increasing.size() - 1;
    std::vector<int> result;
    for (int i = n - 1; i >= 0; i--) {
        if (index[i] == cur) {
            result.push_back(array[i]);
            cur--;
        }
    }
    
    // Print result
    std::reverse(result.begin(), result.end());
    std::cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            std::cout << result[i] << '\n';
        } else {
            std::cout << result[i] << ' ';
        }
    }
    
    return 0;
}
