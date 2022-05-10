#include <iostream>
#include <vector>

// Solving BOJ 15681

void getSubTreeNodes(
    int current,
    std::vector< std::vector<int> >& connection,
    std::vector<int>& subTreeNodes,
    std::vector<bool>& visited) {
    
    int curSubTreeNodes = 1;
    visited[current] = true;
    
    for (int i = 0; i < connection[current].size(); i++) {
        const int nextNode = connection[current][i];
        
        if (visited[nextNode]) {
            continue;
        }
        
        getSubTreeNodes(nextNode, connection, subTreeNodes, visited);
        curSubTreeNodes += subTreeNodes[nextNode];
    }
    
    subTreeNodes[current] = curSubTreeNodes;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, root, queries;
    std::cin >> n >> root >> queries;
    
    // Get tree connection
    std::vector< std::vector<int> > connection(n + 1, std::vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    
    // Calculate tree DP values
    std::vector<int> subTreeNodes(n + 1, 0);
    std::vector<bool> visited(n + 1, false);
    getSubTreeNodes(root, connection, subTreeNodes, visited);
    
    // Get and answer queries
    for (int i = 0; i < queries; i++) {
        int asked;
        std::cin >> asked;
        std::cout << subTreeNodes[asked] << '\n';
    }

    return 0;
}
