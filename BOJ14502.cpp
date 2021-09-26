#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solving BOJ 14502

const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m;
    std::cin >> n >> m;
    
    // Get lab map
    std::vector< std::vector<int> > lab;
    std::vector< std::pair<int, int> > virusPos;
    int safezones = 0;
    for (int i = 0; i < n; i++) {
        lab.push_back(std::vector<int>());
        for (int j = 0; j < m; j++) {
            int input;
            std::cin >> input;
            
            switch (input) {
                case 0:
                    safezones++;
                    break;
                case 2:
                    virusPos.push_back({i, j});
                    break;
            }
            
            lab[i].push_back(input);
        }
    }
    safezones = safezones - 3 + virusPos.size();
    
    // Get maximum safezone
    int largestSafeZones = 0;
    const int totalSize = n * m;
    for (int i = 0; i < totalSize - 2; i++) {
        const int iRow = i / m;
        const int iCol = i % m;
        
        if (lab[iRow][iCol] != 0) {
            continue;
        }
        
        for (int j = i + 1; j < totalSize - 1; j++) {
            const int jRow = j / m;
            const int jCol = j % m;
            
            if (lab[jRow][jCol] != 0) {
                continue;
            }
            
            for (int k = j + 1; k < totalSize; k++) {
                const int kRow = k / m;
                const int kCol = k % m;
                
                if (lab[kRow][kCol] != 0) {
                    continue;
                }
                
                // Plant extra walls
                lab[iRow][iCol] = 1;
                lab[jRow][jCol] = 1;
                lab[kRow][kCol] = 1;
                
                /*
                // Debug
                for (int I = 0; I < n; I++) {
                    for (int J = 0; J < m; J++) {
                        std::cout << lab[I][J] << ' ';
                    }
                    std::cout << '\n';
                }
                */
                
                // Start getting safezone
                int curSafeZones = safezones;
                std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
                for (std::pair<int, int>& curVirus : virusPos) {
                    std::queue< std::pair<int, int> > next;
                    next.push(curVirus);
                    
                    // Search by BFS
                    // first: row, second: column
                    while (!next.empty()) {
                        std::pair<int, int> cur = next.front();
                        next.pop();
                        
                        // Skip if already visited
                        if (visited[cur.first][cur.second]) {
                            continue;
                        }
                        
                        visited[cur.first][cur.second] = true;
                        curSafeZones--;
                        
                        // Find next space
                        for (int i = 0; i < 4; i++) {
                            int nextR = cur.first + direction[i][0];
                            int nextC = cur.second + direction[i][1];
                            
                            // Skip if out of range
                            if (nextR < 0 || nextR >= n) {
                                continue;
                            }
                            
                            if (nextC < 0 || nextC >= m) {
                                continue;
                            }
                            
                            // Skip if already visited
                            if (visited[nextR][nextC]) {
                                continue;
                            }
                            
                            // Skip if not space
                            if (lab[nextR][nextC] != 0) {
                                continue;
                            }
                            
                            next.push({nextR, nextC});
                        }
                    }
                }
                
                /*
                // Debug
                std::cout << curSafeZones << "\n\n";
                */
                
                // Calculating result
                if (largestSafeZones < curSafeZones) {
                    largestSafeZones = curSafeZones;
                }
                
                // Restore walls
                lab[iRow][iCol] = 0;
                lab[jRow][jCol] = 0;
                lab[kRow][kCol] = 0;
            }
        }
    }
    
    std::cout << largestSafeZones << '\n';
    
    return 0;
}
