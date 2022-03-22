#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 2468

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get size
    int n;
    std::cin >> n;
    
    // Get heights
    std::vector< std::vector<int> > height(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> height[i][j];
        }
    }
    
    // Get maximum safe areas
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int maxSafeAreas = 0;
    for (int curHeight = 0; curHeight <= 100; curHeight++) {
        int curSafeAreas = 0;
        std::vector< std::vector<bool> > visited(n, std::vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Skip if this area is submerged or already visited
                if (height[i][j] <= curHeight || visited[i][j]) {
                    continue;
                }
                
                // Start seeking this safe area
                curSafeAreas++;
                
                // first: row, second: col
                std::queue< std::pair<int, int> > next;
                next.push({i, j});
                
                while (!next.empty()) {
                    std::pair<int, int> cur = next.front();
                    next.pop();
                    
                    const int curR = cur.first;
                    const int curC = cur.second;
                    
                    // Skip if this area is submerged or already visited
                    if (height[curR][curC] <= curHeight || visited[curR][curC]) {
                        continue;
                    }
                    
                    visited[curR][curC] = true;
                    
                    // Seek next
                    for (int k = 0; k < 4; k++) {
                        const int nextR = curR + direction[k][0];
                        const int nextC = curC + direction[k][1];
                        
                        // Skip out of range
                        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) {
                            continue;
                        }
                        
                        // Skip submerged
                        if (height[nextR][nextC] <= curHeight) {
                            continue;
                        }
                        
                        // Skip visited
                        if (visited[nextR][nextC]) {
                            continue;
                        }
                        
                        next.push({nextR, nextC});
                    }
                }
            }
        }
        
        if (maxSafeAreas < curSafeAreas) {
            maxSafeAreas = curSafeAreas;
        }
    }
    
    std::cout << maxSafeAreas << '\n';
    
    return 0;
}
