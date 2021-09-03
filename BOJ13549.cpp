#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solving BOJ 13549

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int current, target;
    std::cin >> current >> target;
    
    // Dijkstra solution
    std::vector<bool> visited(100001, false);
    std::vector<int> reachTime(100001, 2000000000);
    std::priority_queue< std::pair<int, int> > next;
    next.push({0, current});
    
    // first: seconds, second: position
    reachTime[current] = 0;
    while (!next.empty()) {
        std::pair<int, int> curInfo = next.top();
        next.pop();
        
        if (visited[curInfo.second]) {
            continue;
        }
        
        visited[curInfo.second] = true;
        
        if (curInfo.second == target) {
            break;
        }
        
        // If -1 movement is in range
        int rangeMinus1 = curInfo.second - 1;
        if (0 <= rangeMinus1 && rangeMinus1 <= 100000) {
            int alt = reachTime[curInfo.second] + 1;
            if (reachTime[rangeMinus1] > alt) {
                reachTime[rangeMinus1] = alt;
                next.push({-alt, rangeMinus1});
            }
        }
        
        // If +1 movement is in range
        int rangePlus1 = curInfo.second + 1;
        if (0 <= rangePlus1 && rangePlus1 <= 100000) {
            int alt = reachTime[curInfo.second] + 1;
            if (reachTime[rangePlus1] > alt) {
                reachTime[rangePlus1] = alt;
                next.push({-alt, rangePlus1});
            }
        }
        
        // If *2 movement is in range
        int rangeMult2 = curInfo.second * 2;
        if (0 <= rangeMult2 && rangeMult2 <= 100000) {
            int alt = reachTime[curInfo.second];
            if (reachTime[rangeMult2] > alt) {
                reachTime[rangeMult2] = alt;
                next.push({-alt, rangeMult2});
            }
        }
    }
    
    std::cout << reachTime[target] << '\n';
    
    return 0;
}
