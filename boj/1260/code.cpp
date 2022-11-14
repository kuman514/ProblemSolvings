#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

// Solving BOJ 1260

void invokeDFS(int cur, std::vector< std::vector<int> >& connection, std::vector<bool>& visitedDFS, std::vector<int>& resultDFS) {
    // Skip this vertex if visited
    if (visitedDFS[cur]) {
        return;
    }
    
    // Paint this vertex visited
    visitedDFS[cur] = true;
    resultDFS.push_back(cur);
    
    // Seek next
    for (int i = 0; i < connection[cur].size(); i++) {
        // Skip vertexes already visited
        if (visitedDFS[connection[cur][i]]) {
            continue;
        }
        
        invokeDFS(connection[cur][i], connection, visitedDFS, resultDFS);
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get vertexes, edges, and starting vertex
    int n, m, v;
    std::cin >> n >> m >> v;
    
    // Get edges' information
    std::vector< std::vector<int> > connection(n + 1, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        
        connection[from].push_back(to);
        connection[to].push_back(from);
    }
    
    // Sort connected vertexes in ascending order
    for (int i = 0; i <= n; i++) {
        std::sort(connection[i].begin(), connection[i].end());
    }
    
    // Backtrackig DFS
    std::vector<bool> visitedDFS(n + 1, false);
    std::vector<int> resultDFS;
    invokeDFS(v, connection, visitedDFS, resultDFS);
    
    // BFS
    std::vector<bool> visitedBFS(n + 1, false);
    std::vector<int> resultBFS;
    std::queue<int> nextBFS;
    
    nextBFS.push(v);
    while (!nextBFS.empty()) {
        int cur = nextBFS.front();
        nextBFS.pop();
        
        // Already visited?
        if (visitedBFS[cur]) {
            continue;
        }
        
        // Paint this vertex visited
        visitedBFS[cur] = true;
        resultBFS.push_back(cur);
        
        // Seek next
        for (int i = 0; i < connection[cur].size(); i++) {
            // Skip vertexes already visited
            if (visitedBFS[connection[cur][i]]) {
                continue;
            }
            
            nextBFS.push(connection[cur][i]);
        }
    }
    
    // Print DFS result
    for (int i = 0; i < resultDFS.size(); i++) {
        if (i < resultDFS.size() - 1) {
            std::cout << resultDFS[i] << ' ';
        } else {
            std::cout << resultDFS[i] << '\n';
        }
    }
    
    // Print BFS result
    for (int i = 0; i < resultBFS.size(); i++) {
        if (i < resultBFS.size() - 1) {
            std::cout << resultBFS[i] << ' ';
        } else {
            std::cout << resultBFS[i] << '\n';
        }
    }

    return 0;
}
