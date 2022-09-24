#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 15653

struct Info {
    int moves;
    int redRow;
    int redCol;
    int blueRow;
    int blueCol;
};

void move(
    std::vector< std::vector<char> >& map,
    std::queue<Info>& next,
    Info& cur,
    int dir,
    std::vector< std::vector< std::vector< std::vector<bool> > > >& redBlueVisited
) {
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const int height = map.size();
    const int width = map[0].size();
    
    int nextMove = cur.moves + 1;
    int nextRedRow = cur.redRow;
    int nextRedCol = cur.redCol;
    int nextBlueRow = cur.blueRow;
    int nextBlueCol = cur.blueCol;
    
    // Move red first
    while (map[nextRedRow][nextRedCol] != 'O') {
        int tmpNextR = nextRedRow + direction[dir][0];
        int tmpNextC = nextRedCol + direction[dir][1];
        
        // If get to the hole
        if (map[tmpNextR][tmpNextC] == 'O') {
            nextRedRow = tmpNextR;
            nextRedCol = tmpNextC;
            break;
        }
        
        // If blocked by a wall
        if (map[tmpNextR][tmpNextC] == '#') {
            break;
        }
        
        // If blocked by Blue
        if (tmpNextR == nextBlueRow && tmpNextC == nextBlueCol) {
            break;
        }
        
        nextRedRow = tmpNextR;
        nextRedCol = tmpNextC;
    }
    
    // Move blue
    while (map[nextBlueRow][nextBlueCol] != 'O') {
        int tmpNextR = nextBlueRow + direction[dir][0];
        int tmpNextC = nextBlueCol + direction[dir][1];
        
        // If get to the hole
        if (map[tmpNextR][tmpNextC] == 'O') {
            nextBlueRow = tmpNextR;
            nextBlueCol = tmpNextC;
            break;
        }
        
        // If blocked by a wall
        if (map[tmpNextR][tmpNextC] == '#') {
            break;
        }
        
        // If blocked by Red
        if (tmpNextR == nextRedRow && tmpNextC == nextRedCol) {
            break;
        }
        
        nextBlueRow = tmpNextR;
        nextBlueCol = tmpNextC;
    }
    
    // Move red final
    while (map[nextRedRow][nextRedCol] != 'O') {
        int tmpNextR = nextRedRow + direction[dir][0];
        int tmpNextC = nextRedCol + direction[dir][1];
        
        // If get to the hole
        if (map[tmpNextR][tmpNextC] == 'O') {
            nextRedRow = tmpNextR;
            nextRedCol = tmpNextC;
            break;
        }
        
        // If blocked by a wall
        if (map[tmpNextR][tmpNextC] == '#') {
            break;
        }
        
        // If blocked by Blue
        if (tmpNextR == nextBlueRow && tmpNextC == nextBlueCol) {
            break;
        }
        
        nextRedRow = tmpNextR;
        nextRedCol = tmpNextC;
    }
    
    // Blue got the hole?
    if (map[nextBlueRow][nextBlueCol] == 'O') {
        return;
    }
    
    // No coords change?
    if (nextRedRow == cur.redRow && nextRedCol == cur.redCol && nextBlueRow == cur.blueRow && nextBlueCol == cur.blueCol) {
        return;
    }
    
    // Already visited?
    if (redBlueVisited[nextRedRow][nextRedCol][nextBlueRow][nextBlueCol]) {
        return;
    }
    
    next.push({nextMove, nextRedRow, nextRedCol, nextBlueRow, nextBlueCol});
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int initRedR, initRedC, initBlueR, initBlueC;
    std::vector< std::vector<char> > map(n, std::vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            
            switch (map[i][j]) {
                case 'R':
                    initRedR = i;
                    initRedC = j;
                    map[i][j] = '.';
                    break;
                case 'B':
                    initBlueR = i;
                    initBlueC = j;
                    map[i][j] = '.';
                    break;
            }
        }
    }
    
    std::queue<Info> next;
    int result = -1;
    next.push({0, initRedR, initRedC, initBlueR, initBlueC});
    std::vector< std::vector< std::vector< std::vector<bool> > > > redBlueVisited(
        n,
        std::vector< std::vector< std::vector<bool> > >(
            m,
            std::vector< std::vector<bool> >(
                n,
                std::vector<bool> (
                    m, false
                )
            )
        )
    );
    while (!next.empty()) {
        Info cur = next.front();
        next.pop();
        
        if (redBlueVisited[cur.redRow][cur.redCol][cur.blueRow][cur.blueCol]) {
            continue;
        }
        redBlueVisited[cur.redRow][cur.redCol][cur.blueRow][cur.blueCol] = true;
        
        if (map[cur.redRow][cur.redCol] == 'O') {
            result = cur.moves;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            move(map, next, cur, i, redBlueVisited);
        }
    }
    
    std::cout << result << '\n';
    
    return 0;
}
