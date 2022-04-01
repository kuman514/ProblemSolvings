#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 16173

struct info {
    int jumps;
    int row;
    int col;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector< std::vector<int> > jumpAmount(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> jumpAmount[i][j];
        }
    }
    
    const int direction[2][2] = {{1, 0}, {0, 1}};
    std::queue<info> next;
    std::vector< std::vector<bool> > visited(n, std::vector<bool>(n, 0));
    next.push({0, 0, 0});
    bool completed = false;
    
    while (!next.empty()) {
        info cur = next.front();
        next.pop();
        
        if (visited[cur.row][cur.col]) {
            continue;
        }
        
        visited[cur.row][cur.col] = true;
        
        if (jumpAmount[cur.row][cur.col] == -1) {
            completed = true;
            break;
        }
        
        for (int i = 0; i < 2; i++) {
            const int nextR = cur.row + (jumpAmount[cur.row][cur.col] * direction[i][0]);
            const int nextC = cur.col + (jumpAmount[cur.row][cur.col] * direction[i][1]);
            const int nextJ = cur.jumps + 1;
            
            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) {
                continue;
            }
            
            next.push({nextJ, nextR, nextC});
        }
    }
    
    std::cout << (completed ? "HaruHaru" : "Hing") << '\n';

    return 0;
}
