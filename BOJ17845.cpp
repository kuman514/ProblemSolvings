#include <iostream>
#include <vector>
#include <utility>

// Solving BOJ 17845

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k;
    // first: priority, second: cost time
    std::vector< std::pair<int, int> > subjects;
    std::cin >> n >> k;
    
    // Get input
    for (int i = 0; i < k; i++) {
        int l, t;
        std::cin >> l >> t;
        subjects.push_back({l, t});
    }
    
    std::vector<int> highestPriority(n + 1, 0);
    for (int i = 0; i < subjects.size(); i++) {
        const int currentPriority = subjects[i].first;
        const int currentCost = subjects[i].second;
        for (int j = n; j >= currentCost; j--) {
            const int priorityIfYouGet = highestPriority[j - currentCost] + currentPriority;
            if (highestPriority[j] < priorityIfYouGet) {
                highestPriority[j] = priorityIfYouGet;
            }
        }
    }
    
    std::cout << highestPriority[n] << '\n';

    return 0;
}
