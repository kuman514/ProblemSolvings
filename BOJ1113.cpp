#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 1113

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // Get sizes
    int n, m;
    std::cin >> n >> m;
    
    // Get map heights
    std::vector< std::vector<int> > height(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            std::cin >> input;
            height[i][j] = static_cast<int>(input - '0');
        }
    }
    
    // Get available sizes for each height
    int totalSize = 0;
    for (int curHeight = 1; curHeight <= 9; curHeight++) {
        std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
        
        // Search height[i][j] <= curHeight
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If height[i][j] <= curHeight and not visited, start BFS
                if (!visited[i][j] && height[i][j] <= curHeight) {
                    int curSize = 0;
                    bool flooded = false;
                    
                    // first: row, second: column
                    std::queue< std::pair<int, int> > next;
                    next.push({i, j});
                    while (!next.empty()) {
                        std::pair<int, int> cur = next.front();
                        next.pop();
                        
                        const int curR = cur.first;
                        const int curC = cur.second;
                        
                        // If already visited, skip this position
                        if (visited[curR][curC]) {
                            continue;
                        }
                        
                        // Paint this visited, increase curSize
                        visited[curR][curC] = true;
                        curSize++;
                        
                        // Seek next
                        for (int k = 0; k < 4; k++) {
                            const int nextR = curR + direction[k][0];
                            const int nextC = curC + direction[k][1];
                            
                            // If out of range, this is flooded
                            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
                                flooded = true;
                                continue;
                            }
                            
                            // If already visited, skip
                            if (visited[nextR][nextC]) {
                                continue;
                            }
                            
                            // If blocked by higher ground, skip
                            if (curHeight < height[nextR][nextC]) {
                                continue;
                            }
                            
                            next.push({nextR, nextC});
                        }
                    }
                    
                    if (!flooded) {
                        totalSize += curSize;
                    }
                }
            }
        }
        
    }
    
    std::cout << totalSize << '\n';

    return 0;
}
