#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 2933 again

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get sizes
    int n, m;
    std::cin >> n >> m;
    
    // Get mineral informations
    std::vector< std::vector<bool> > mineral(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            std::cin >> input;
            
            switch (input) {
                case '.':
                    mineral[i][j] = false;
                    break;
                case 'x':
                    mineral[i][j] = true;
                    break;
            }
        }
    }
    
    // Get thrown informations
    int throws;
    std::cin >> throws;
    std::vector<int> thrownHeights(throws, 0);
    for (int i = 0; i < throws; i++) {
        int input;
        std::cin >> input;
        thrownHeights[i] = n - input;
    }
    
    // Play the throw game
    const int nextDirection[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int cur = 0; cur < throws; cur++) {
        const int curHeight = thrownHeights[cur];
        const int startFrom = (cur % 2 == 0 ? 0 : (m - 1));
        const int direction = (cur % 2 == 0 ? 1 : -1);
        
        // Destroy a mineral
        for (int j = startFrom; 0 <= j && j < m; j += direction) {
            if (mineral[curHeight][j]) {
                mineral[curHeight][j] = false;
                break;
            }
        }
        
        // Copy previous mineral map
        std::vector< std::vector<bool> > prevMineral(n, std::vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prevMineral[i][j] = mineral[i][j];
            }
        }
        
        // Search clusters and their falling heights
        std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                // If already visited or no previous mineral, skip here
                if (visited[i][j] || !prevMineral[i][j]) {
                    continue;
                }
                
                // Search mineral area by using BFS
                // first: row, second: col
                std::queue< std::pair<int, int> > next;
                std::vector< std::pair<int, int> > savedMinerals;
                
                next.push({i, j});
                while (!next.empty()) {
                    std::pair<int, int> cur = next.front();
                    next.pop();
                    
                    const int curR = cur.first;
                    const int curC = cur.second;
                    
                    // Skip if already visited
                    if (visited[curR][curC]) {
                        continue;
                    }
                    
                    // Paint here visited
                    visited[curR][curC] = true;
                    
                    // Take and save this mineral
                    mineral[curR][curC] = false;
                    savedMinerals.push_back({curR, curC});
                    
                    // Seek next
                    for (int k = 0; k < 4; k++) {
                        const int nextR = curR + nextDirection[k][0];
                        const int nextC = curC + nextDirection[k][1];
                        
                        // Out of range?
                        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
                            continue;
                        }
                        
                        // Already visited?
                        if (visited[nextR][nextC]) {
                            continue;
                        }
                        
                        // No previous mineral?
                        if (!prevMineral[nextR][nextC]) {
                            continue;
                        }
                        
                        // Push to next
                        next.push({nextR, nextC});
                    }
                }
                
                // Calculate falling height
                int fallingHeight = n - 1;
                for (int k = 0; k < savedMinerals.size(); k++) {
                    const int curR = savedMinerals[k].first;
                    const int curC = savedMinerals[k].second;
                    
                    int tmpHeight = 0;
                    while (tmpHeight < n - curR) {
                        if (mineral[curR + tmpHeight][curC]) {
                            break;
                        }
                        
                        tmpHeight++;
                    }
                    
                    tmpHeight--;
                    if (fallingHeight > tmpHeight) {
                        fallingHeight = tmpHeight;
                    }
                }
                
                // Set minerals
                for (int k = 0; k < savedMinerals.size(); k++) {
                    const int curR = savedMinerals[k].first;
                    const int curC = savedMinerals[k].second;
                    
                    mineral[curR + fallingHeight][curC] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << (mineral[i][j] ? 'x' : '.');
        }
        std::cout << '\n';
    }
    
    return 0;
}
