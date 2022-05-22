#include <iostream>
#include <vector>

// Solving BOJ 16724

struct Coord {
    int row;
    int col;
};

bool operator==(Coord& left, Coord& right) {
    return ((left.row == right.row) && (left.col == right.col));
}

Coord findParent(Coord current, std::vector< std::vector<Coord> >& parent) {
    int curRow = current.row;
    int curCol = current.col;
    
    if (curRow != parent[curRow][curCol].row || curCol != parent[curRow][curCol].col) {
        // Update it's parent if not updated yet
        parent[curRow][curCol] = findParent(parent[curRow][curCol], parent);
    }
    
    return parent[curRow][curCol];
}

void addUnion(Coord a, Coord b, std::vector< std::vector<Coord> >& parent) {
    Coord start = a;
    Coord end = b;
    
    if (a.row > b.row) {
        start = b;
        end = a;
    } else if (a.row == b.row && a.col < b.col) {
        start = b;
        end = a;
    }
    
    Coord superParent = findParent(start, parent);
    Coord subParent = findParent(end, parent);
    
    parent[subParent.row][subParent.col] = parent[superParent.row][superParent.col];
}

bool hasSameParent(Coord a, Coord b, std::vector< std::vector<Coord> >& parent) {
    Coord parentA = findParent(a, parent);
    Coord parentB = findParent(b, parent);
    
    return (parent[parentA.row][parentA.col] == parent[parentB.row][parentB.col]);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get sizes
    int n, m;
    std::cin >> n >> m;
    
    // Get directions
    const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector< std::vector<int> > mapDir(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char input;
            std::cin >> input;
            
            switch (input) {
                case 'U':
                    mapDir[i][j] = 0;
                    break;
                case 'D':
                    mapDir[i][j] = 1;
                    break;
                case 'L':
                    mapDir[i][j] = 2;
                    break;
                case 'R':
                    mapDir[i][j] = 3;
                    break;
            }
        }
    }
    
    // Initialize parent
    std::vector< std::vector<Coord> > parent(n, std::vector<Coord>(m, {0, 0}));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i][j] = {i, j};
        }
    }
    
    // Get safe zone areas by using DFS
    std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If already visited, skip
            if (visited[i][j]) {
                continue;
            }
            
            // Start
            Coord current = {i, j};
            Coord next = {i + direction[mapDir[i][j]][0], j + direction[mapDir[i][j]][1]};
            while (!visited[current.row][current.col]) {
                visited[current.row][current.col] = true;
                
                if (hasSameParent(current, next, parent)) {
                    break;
                }
                
                addUnion(current, next, parent);
                
                current = next;
                next = {
                    next.row + direction[mapDir[next.row][next.col]][0],
                    next.col + direction[mapDir[next.row][next.col]][1]
                };
            }
        }
    }
    
    // Check and count real parent
    int safeZones = 0;
    std::vector< std::vector<bool> > realParent(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Coord curParent = findParent({i, j}, parent);
            if (!realParent[curParent.row][curParent.col]) {
                realParent[curParent.row][curParent.col] = true;
                safeZones++;
            }
        }
    }
    
    std::cout << safeZones << '\n';
    
    return 0;
}
