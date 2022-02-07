#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 17143

struct Shark {
    int speed;
    int direction;
    int size;
};

struct Coords {
    int row;
    int col;
};

bool sortSharksBySize(Shark& lhs, Shark& rhs) {
    return (lhs.size > rhs.size);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // 0: up, 1: down, 2: right, 3: left
    const int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int nextDirection[4] = {1, 0, 3, 2};
    
    int r, c, m;
    std::cin >> r >> c >> m;
    
    // Get sharks' information
    std::vector< std::vector< std::vector<Shark> > > sharks(
        r,
        std::vector< std::vector<Shark> >(
            c,
            std::vector<Shark>()
        )
    );
    for (int i = 0; i < m; i++) {
        int y, x, s, d, z;
        std::cin >> y >> x >> s >> d >> z;
        sharks[y - 1][x - 1].push_back({s, d - 1, z});
    }
    
    // Simulate shark capture
    int fishermanPos = -1;
    int capturedSize = 0;
    while (fishermanPos < c - 1) {
        // The fisherman moves
        fishermanPos++;
        
        /*
        // Debug
        std::cout << "fisherman: " << fishermanPos << '\n';
        std::cout << "=================================\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (sharks[i][j].size() > 0) {
                    std::cout << sharks[i][j][0].size << ' ';
                } else {
                    std::cout << '.' << ' ';
                }
            }
            std::cout << '\n';
        }
        std::cout << "=================================\n";
        */
        
        // The fisherman captures a shark nearst the ground
        for (int i = 0; i < r; i++) {
            if (sharks[i][fishermanPos].size() > 0) {
                capturedSize += sharks[i][fishermanPos][0].size;
                sharks[i][fishermanPos].pop_back();
                break;
            }
        }
        
        /*
        // Debug
        std::cout << "capturedSize: " << capturedSize << '\n';
        std::cout << "=================================\n";
        */
        
        // The sharks move
        std::vector< std::pair<Coords, Shark> > nextSharks;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (sharks[i][j].size() > 0) {
                    int nextRow = i + (direction[sharks[i][j][0].direction][0] * sharks[i][j][0].speed);
                    int nextCol = j + (direction[sharks[i][j][0].direction][1] * sharks[i][j][0].speed);
                    int nextDir = sharks[i][j][0].direction;
                    
                    while (nextRow < 0 || nextRow >= r) {
                        if (nextRow < 0) {
                            nextRow = -nextRow;
                            nextDir = nextDirection[nextDir];
                        }
                        
                        if (nextRow >= r) {
                            nextRow = r - 1 - (nextRow - r + 1);
                            nextDir = nextDirection[nextDir];
                        }
                    }
                    
                    while (nextCol < 0 || nextCol >= c) {
                        if (nextCol < 0) {
                            nextCol = -nextCol;
                            nextDir = nextDirection[nextDir];
                        }
                        
                        if (nextCol >= c) {
                            nextCol = c - 1 - (nextCol - c + 1);
                            nextDir = nextDirection[nextDir];
                        }
                    }
                    
                    nextSharks.push_back({
                        {nextRow, nextCol},
                        {sharks[i][j][0].speed, nextDir, sharks[i][j][0].size}
                    });
                    sharks[i][j].pop_back();
                }
            }
        }
        for (int i = 0; i < nextSharks.size(); i++) {
            sharks[nextSharks[i].first.row][nextSharks[i].first.col].push_back(nextSharks[i].second);
        }
        
        // The 1 largest shark in each cell can survive
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (sharks[i][j].size() > 1) {
                    std::sort(sharks[i][j].begin(), sharks[i][j].end(), sortSharksBySize);
                    while (sharks[i][j].size() > 1) {
                        sharks[i][j].pop_back();
                    }
                }
            }
        }
        
        /*
        // Debug
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (sharks[i][j].size() > 0) {
                    std::cout << sharks[i][j][0].size << ' ';
                } else if (sharks[i][j].size() > 1) {
                    std::cout << 'E' << ' ';
                } else {
                    std::cout << '.' << ' ';
                }
            }
            std::cout << '\n';
        }
        std::cout << "\n\n";
        */
    }
    
    std::cout << capturedSize << '\n';

    return 0;
}
