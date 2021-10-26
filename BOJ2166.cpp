#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 2166

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get input
    int n;
    std::cin >> n;
    
    // Get coords
    std::vector< std::pair<int, int> > coords;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        coords.push_back({a, b});
    }

    /*
        S = (1 / 2) * | x1 x2 ... xn x1 | = (| x1 * y2 + x2 * y3 + ... + xn * y1 - (x2 * y1 + x3 * y2 + ... + x1 * yn) |) / 2
                      | y1 y2 ... yn y1 |
    */
    
    // First
    long long first = 0LL;
    for (int i = 0; i < n; i++) {
        first += (static_cast<long long>(coords[i].first) * static_cast<long long>(coords[(i + 1) % n].second));
    }
    
    // Second
    long long second = 0LL;
    for (int i = 0; i < n; i++) {
        second += (static_cast<long long>(coords[i].second) * static_cast<long long>(coords[(i + 1) % n].first));
    }
    
    long long result = std::abs(first - second);
    std::cout << (result / 2) << (result % 2 ? ".5" : ".0") << '\n';
    
    return 0;
}
