#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 1194

struct MoveInfo {
    int row;
    int col;
    int moves;
    int keys;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::vector<int> bitKey(6, 0);
    for (int i = 0; i < 6; i++) {
        bitKey[i] = (1 << i);
    }
    
    int n, m;
    std::cin >> n >> m;
    
    int startRow = 0, startCol = 0;
    std::vector< std::vector<char> > map(n, std::vector<char>(m, static_cast<char>(0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            
            if (map[i][j] == '0') {
                startRow = i;
                startCol = j;
                map[i][j] == '.';
            }
        }
    }
    
    int result = -1;
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::vector< std::vector< std::vector<bool> > > visited(
        n,
        std::vector< std::vector<bool> >(
            m,
            std::vector<bool>(64, false)
        )
    );
    std::queue<MoveInfo> next;
    next.push({startRow, startCol, 0, 0});
    while (!next.empty()) {
        MoveInfo cur = next.front();
        next.pop();
        
        int row = cur.row;
        int col = cur.col;
        int moves = cur.moves;
        int keys = cur.keys;
        
        if (visited[row][col][keys]) {
            continue;
        }
        
        visited[row][col][keys] = true;
        
        if (map[row][col] == '1') {
            result = moves;
            break;
        }
        
        if ('a' <= map[row][col] && map[row][col] <= 'f') {
            keys |= bitKey[static_cast<int>(map[row][col] - 'a')];
        }
        
        const int nextM = moves + 1;
        for (int i = 0; i < 4; i++) {
            const int nextR = row + direction[i][0];
            const int nextC = col + direction[i][1];
            
            // Out of range
            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
                continue;
            }
            
            // Visited
            if (visited[nextR][nextC][keys]) {
                continue;
            }
            
            // Wall
            if (map[nextR][nextC] == '#') {
                continue;
            }
            
            // Door but don't have key
            if (('A' <= map[nextR][nextC] && map[nextR][nextC] <= 'F') && !(keys & bitKey[static_cast<int>(map[nextR][nextC] - 'A')])) {
                continue;
            }
            
            next.push({nextR, nextC, nextM, keys});
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
