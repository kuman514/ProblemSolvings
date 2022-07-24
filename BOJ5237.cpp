#include <iostream>
#include <queue>
#include <vector>

// Solving BOJ 5237

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int testCases;
    std::cin >> testCases;
    
    for (int t = 0; t < testCases; t++) {
        int nodes, edges;
        std::cin >> nodes >> edges;
        
        std::vector< std::vector<int> > connections(nodes, std::vector<int>());
        for (int e = 0; e < edges; e++) {
            int origin, destination;
            std::cin >> origin >> destination;
            connections[origin].push_back(destination);
            connections[destination].push_back(origin);
        }
        
        std::queue<int> next;
        std::vector<bool> isVisited(nodes, false);
        next.push(0);
        while (!next.empty()) {
            int cur = next.front();
            next.pop();
            
            if (isVisited[cur]) {
                continue;
            }
            isVisited[cur] = true;
            
            for (int e = 0; e < connections[cur].size(); e++) {
                if (isVisited[connections[cur][e]]) {
                    continue;
                }
                
                next.push(connections[cur][e]);
            }
        }
        
        bool isAllConnected = true;
        for (int i = 0; i < nodes; i++) {
            if (!isVisited[i]) {
                isAllConnected = false;
                break;
            }
        }
        
        std::cout << (isAllConnected ? "Connected." : "Not connected.") << '\n';
    }

    return 0;
}
