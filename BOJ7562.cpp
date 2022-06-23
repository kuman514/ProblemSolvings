#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 7562

struct position {
    int row;
    int col;
    int moves;
};

const int direction[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int testCases;
    std::cin >> testCases;
    
    for (int t = 0; t < testCases; t++) {
        int n;
        std::cin >> n;
        
        int startR, startC;
        std::cin >> startR >> startC;
        
        int endR, endC;
        std::cin >> endR >> endC;
        
        std::vector< std::vector<bool> > visited(n, std::vector<bool>(n, false));
        std::queue<position> next;
        next.push({startR, startC, 0});
        
        while (!next.empty()) {
            position cur = next.front();
            next.pop();
            
            if (visited[cur.row][cur.col]) {
                continue;
            }
            visited[cur.row][cur.col] = true;
            
            if (cur.row == endR && cur.col == endC) {
                std::cout << cur.moves << '\n';
                break;
            }
            
            const int nextM = cur.moves + 1;
            for (int i = 0; i < 8; i++) {
                const int nextR = cur.row + direction[i][0];
                const int nextC = cur.col + direction[i][1];
                
                if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) {
                    continue;
                }
                
                if (visited[nextR][nextC]) {
                    continue;
                }
                
                next.push({nextR, nextC, nextM});
            }
        }
    }

    return 0;
}
