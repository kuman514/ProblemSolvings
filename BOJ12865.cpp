#include <iostream>
#include <vector>
#include <utility>

// Solving BOJ 12865

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k;
    // first: weight, second: value
    std::vector< std::pair<int, int> > items;
    std::cin >> n >> k;
    
    // Get input
    for (int i = 0; i < n; i++) {
        int w, v;
        std::cin >> w >> v;
        items.push_back({w, v});
    }
    
    std::vector<int> highestValue(k + 1, 0);
    for (int i = 0; i < n; i++) {
        const int currentWeight = items[i].first;
        const int currentValue = items[i].second;
        for (int j = k; j >= currentWeight; j--) {
            const int valueIfYouPutIn = highestValue[j - currentWeight] + currentValue;
            if (highestValue[j] < valueIfYouPutIn) {
                highestValue[j] = valueIfYouPutIn;
            }
        }
    }
    
    std::cout << highestValue[k] << '\n';

    return 0;
}
