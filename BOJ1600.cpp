#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 1600

struct position {
    int row;
    int col;
    int moves;
    int remain;
};

const int direction[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
const int altDirection[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int k;
    std::cin >> k;
    
    int w, h;
    std::cin >> w >> h;
    
    std::vector< std::vector<bool> > obstacle(h, std::vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int input;
            std::cin >> input;
            obstacle[i][j] = (input == 1);
        }
    }
    
    const int endR = h - 1;
    const int endC = w - 1;
    
    std::vector< std::vector< std::vector<bool> > > visited(
        k + 1,
        std::vector< std::vector<bool> >(
            h,
            std::vector<bool>(w, false)
        )
    );
    std::queue<position> next;
    next.push({0, 0, 0, k});
    
    int result = -1;
    while (!next.empty()) {
        position cur = next.front();
        next.pop();
        
        if (visited[cur.remain][cur.row][cur.col]) {
            continue;
        }
        visited[cur.remain][cur.row][cur.col] = true;
        
        if (cur.row == endR && cur.col == endC) {
            result = cur.moves;
            break;
        }
        
        const int nextM = cur.moves + 1;
        
        const int nextRemain = cur.remain - 1;
        if (nextRemain >= 0) {
            for (int i = 0; i < 8; i++) {
                const int nextR = cur.row + direction[i][0];
                const int nextC = cur.col + direction[i][1];
                
                if (nextR < 0 || nextR >= h || nextC < 0 || nextC >= w) {
                    continue;
                }
                
                if (obstacle[nextR][nextC]) {
                    continue;
                }
                
                if (visited[nextRemain][nextR][nextC]) {
                    continue;
                }
                
                next.push({nextR, nextC, nextM, nextRemain});
            }
        }
        
        for (int i = 0; i < 4; i++) {
            const int nextR = cur.row + altDirection[i][0];
            const int nextC = cur.col + altDirection[i][1];
            
            if (nextR < 0 || nextR >= h || nextC < 0 || nextC >= w) {
                continue;
            }
                
            if (obstacle[nextR][nextC]) {
                continue;
            }
            
            if (visited[cur.remain][nextR][nextC]) {
                continue;
            }
            
            next.push({nextR, nextC, nextM, cur.remain});
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
