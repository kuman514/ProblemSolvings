#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solving BOJ 2638

const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m;
    std::cin >> n >> m;
    
    // Get cheese map
    std::vector< std::vector<bool> > isCheese;
    int remain = 0;
    for (int i = 0; i < n; i++) {
        isCheese.push_back(std::vector<bool>());
        for (int j = 0; j < m; j++) {
            int input;
            std::cin >> input;
            isCheese[i].push_back((input == 1 ? true : false));
            remain += input;
        }
    }
    
    // Let all the cheese melt
    int elapsedHours = 0;
    
    /*
    // Debug
    std::cout << elapsedHours << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << (isCheese[i][j] ? '#' : '.') << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    */
    
    while (remain > 0) {
        // Count directions that each cheese meets air
        std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
        std::vector< std::vector<int> > directionsMeetingAir(n, std::vector<int>(m, 0));
        std::vector< std::pair<int, int> > markedToMelt;
        
        // Search by BFS
        // first: row, second: column
        std::queue< std::pair<int, int> > next;
        next.push({0, 0});
        while (!next.empty()) {
            std::pair<int, int> cur = next.front();
            next.pop();
            
            // Skip if already visited
            if (visited[cur.first][cur.second]) {
                continue;
            }
            
            visited[cur.first][cur.second] = true;
            
            // Find cheese around and next space
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
                
                if (isCheese[nextR][nextC]) {
                    // If the cheese meets air
                    if (directionsMeetingAir[nextR][nextC] < 2) {
                        directionsMeetingAir[nextR][nextC]++;
                        if (directionsMeetingAir[nextR][nextC] >= 2) {
                            markedToMelt.push_back({nextR, nextC});
                        }
                    }
                } else {
                    // If next space
                    if (!visited[nextR][nextC]) {
                        next.push({nextR, nextC});
                    }
                }
            }
        }
        
        // Cheese melt
        for (std::pair<int, int>& pos : markedToMelt) {
            isCheese[pos.first][pos.second] = false;
            remain--;
        }
        
        elapsedHours++;
        
        /*
        // Debug
        std::cout << elapsedHours << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << (isCheese[i][j] ? '#' : '.') << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        */
    }
    
    std::cout << elapsedHours << '\n';
    
    return 0;
}
