#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solving BOJ 12851

const int notVisited = 100002;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, k;
    std::cin >> n >> k;
    
    // Init
    // first: minimum time, second: ways in minimum time
    std::vector< std::pair<int, int> > minTimeAndWays(100001, {notVisited, 0});
    // first: current position, second: elapsed time
    std::queue< std::pair<int, int> > next;
    
    next.push({n, 0});
    while (!next.empty()) {
        std::pair<int, int> current = next.front();
        next.pop();
        
        // Already visited but faster than before
        if (current.second < minTimeAndWays[current.first].first) {
            minTimeAndWays[current.first].first = current.second;
            minTimeAndWays[current.first].second = 1;
        } else if (current.second == minTimeAndWays[current.first].first) {
            minTimeAndWays[current.first].second++;
        } else {
            continue;
        }
        
        // Go next
        const int nextPos1 = current.first - 1;
        if (nextPos1 >= 0) {
            next.push({nextPos1, current.second + 1});
        }
        
        const int nextPos2 = current.first + 1;
        if (nextPos2 <= 100000) {
            next.push({nextPos2, current.second + 1});
        }
        
        const int nextPos3 = current.first * 2;
        if (nextPos3 <= 100000) {
            next.push({nextPos3, current.second + 1});
        }
    }
    
    std::cout << minTimeAndWays[k].first << '\n' << minTimeAndWays[k].second << '\n';
    
    return 0;
}
