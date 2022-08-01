#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Solving BOJ 2583

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get sizes and the number of excluded areas
    int m, n, k;
    std::cin >> m >> n >> k;
    
    // Get k excluded areas
    std::vector< std::vector<bool> > excluded(m, std::vector<bool>(n, false));
    for (int cur = 0; cur < k; cur++) {
        int startX, startY, endX, endY;
        std::cin >> startX >> startY >> endX >> endY;
        
        for (int i = startY; i < endY; i++) {
            for (int j = startX; j < endX; j++) {
                excluded[i][j] = true;
            }
        }
    }
    
    /*
    // Debug
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << (excluded[i][j] ? '#' : '.') << ' ';
        }
        std::cout << '\n';
    }
    */
    
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::vector<int> areas;
    std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (excluded[i][j] || visited[i][j]) {
                continue;
            }
            
            int curArea = 0;
            std::queue< std::pair<int, int> > next;
            next.push({i, j});
            while (!next.empty()) {
                std::pair<int, int> cur = next.front();
                next.pop();
                
                int curR = cur.first;
                int curC = cur.second;
                
                if (visited[curR][curC]) {
                    continue;
                }
                
                visited[curR][curC] = true;
                curArea++;
                
                for (int p = 0; p < 4; p++) {
                    const int nextR = curR + direction[p][0];
                    const int nextC = curC + direction[p][1];
                    
                    if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) {
                        continue;
                    }
                    
                    if (excluded[nextR][nextC] || visited[nextR][nextC]) {
                        continue;
                    }
                    
                    next.push({nextR, nextC});
                }
            }
            
            areas.push_back(curArea);
        }
    }
    
    std::sort(areas.begin(), areas.end());
    
    std::cout << areas.size() << '\n';
    for (int i = 0; i < areas.size(); i++) {
        if (i == areas.size() - 1) {
            std::cout << areas[i] << '\n';
        } else {
            std::cout << areas[i] << ' ';
        }
    }

    return 0;
}
