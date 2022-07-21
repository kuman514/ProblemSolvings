#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 1175

struct TargetInfo {
    int row;
    int col;
};

struct MoveInfo {
    int row;
    int col;
    int moves;
    int dir;
    int sent;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::vector<int> bitSent(2, 0);
    for (int i = 0; i < 2; i++) {
        bitSent[i] = (1 << i);
    }
    
    int n, m;
    std::cin >> n >> m;
    
    int startRow = 0, startCol = 0;
    int targets = 0;
    std::vector< std::vector<char> > map(n, std::vector<char>(m, static_cast<char>(0)));
    std::vector<TargetInfo> targetCoords(2, {0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            
            switch (map[i][j]) {
                case 'S':
                    startRow = i;
                    startCol = j;
                    map[i][j] == '.';
                    break;
                case 'C':
                    targetCoords[targets].row = i;
                    targetCoords[targets].col = j;
                    targets++;
                    map[i][j] == '.';
                    break;
            }
        }
    }
    
    int result = -1;
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::vector< std::vector< std::vector< std::vector<bool> > > > visited(
        n,
        std::vector< std::vector< std::vector<bool> > >(
            m,
            std::vector< std::vector<bool> >(
                4,
                std::vector<bool>(4, false)
            )
        )
    );
    
    std::queue<MoveInfo> next;
    for (int i = 0; i < 4; i++) {
        const int nextR = startRow + direction[i][0];
        const int nextC = startCol + direction[i][1];
        
        // Out of range
        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
            continue;
        }
        
        // Wall
        if (map[nextR][nextC] == '#') {
            continue;
        }
        
        next.push({nextR, nextC, 1, i, 0});
    }
    
    while (!next.empty()) {
        MoveInfo cur = next.front();
        next.pop();
        
        int row = cur.row;
        int col = cur.col;
        int dir = cur.dir;
        int sent = cur.sent;
        int moves = cur.moves;
        
        if (visited[row][col][dir][sent]) {
            continue;
        }
        
        visited[row][col][dir][sent] = true;
        
        for (int i = 0; i < 2; i++) {
            if (row == targetCoords[i].row && col == targetCoords[i].col) {
                sent |= bitSent[i];
            }
        }
        
        if (sent == 3) {
            result = moves;
            break;
        }
        
        const int nextM = moves + 1;
        for (int i = 0; i < 4; i++) {
            // Same direciton
            if (i == dir) {
                continue;
            }
            
            const int nextR = row + direction[i][0];
            const int nextC = col + direction[i][1];
            
            // Out of range
            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
                continue;
            }
            
            // Visited
            if (visited[nextR][nextC][dir][sent]) {
                continue;
            }
            
            // Wall
            if (map[nextR][nextC] == '#') {
                continue;
            }
            
            next.push({nextR, nextC, nextM, i, sent});
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
