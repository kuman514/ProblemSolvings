#include <iostream>
#include <vector>
#include <queue>
#include <string>

// Solving BOJ 1261

// first: breach count, second.first: row, second.second: column
typedef std::pair< int, std::pair<int, int> > weightCoord;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int width, height;
    std::cin >> width >> height;
    
    std::vector< std::vector<bool> > wall(height, std::vector<bool>(width, false));
    for (int i = 0; i < height; i++) {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < width; j++) {
            wall[i][j] = (input[j] == '1') ? true : false;
        }
    }

    // Dijkstra solution
    std::vector< std::vector<bool> > visited(height, std::vector<bool>(width, false));
    std::vector< std::vector<int> > breachCount(height, std::vector<int>(width, height * width));
    std::priority_queue<weightCoord> next;
    next.push({0, {0, 0}});
    
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    breachCount[0][0] = 0;
    while (!next.empty()) {
        weightCoord curInfo = next.top();
        next.pop();
        
        int weight = curInfo.first;
        int row = curInfo.second.first;
        int col = curInfo.second.second;
        
        if (visited[row][col]) {
            continue;
        }
        visited[row][col] = true;
        
        if (row == height - 1 && col == width - 1) {
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nextR = row + direction[i][0];
            int nextC = col + direction[i][1];
            
            if (nextR < 0 || nextR >= height) {
                continue;
            }
            
            if (nextC < 0 || nextC >= width) {
                continue;
            }
            
            int alt = breachCount[row][col] + (wall[nextR][nextC] ? 1 : 0);
            if (breachCount[nextR][nextC] > alt) {
                breachCount[nextR][nextC] = alt;
                next.push({-alt, {nextR, nextC}});
            }
        }
    }
    
    std::cout << breachCount[height - 1][width - 1] << '\n';
    
    return 0;
}
