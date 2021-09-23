#include <iostream>
#include <vector>

// Solving BOJ 14938

struct edge {
    int node1;
    int node2;
    int weight;
};

const int INF = 100 * 100 * 15 + 1;

int calculateMaximumObtain(std::vector<edge>& edges, std::vector<int>& itemQuantity, int scope) {
    int n = itemQuantity.size();
    std::vector< std::vector<int> > dist(n, std::vector<int>(n, INF));
    
    // Init dist graph
    for (edge& e : edges) {
        if (dist[e.node1][e.node2] > e.weight) {
            dist[e.node1][e.node2] = e.weight;
        }
        if (dist[e.node2][e.node1] > e.weight) {
            dist[e.node2][e.node1] = e.weight;
        }
    }
    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    // Floyd-Warshall solution
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Get highest result
    int highestResult = 0;
    for (int i = 0; i < n; i++) {
        int result = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= scope) {
                result += itemQuantity[j];
            }
        }
        
        if (highestResult < result) {
            highestResult = result;
        }
    }
    
    return highestResult;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m, r;
    std::cin >> n >> m >> r;
    
    // Get each item quantity
    std::vector<int> itemQuantity;
    for (int i = 0; i < n; i++) {
        int quantity;
        std::cin >> quantity;
        itemQuantity.push_back(quantity);
    }
    
    // Get edges
    std::vector<edge> edges;
    for (int i = 0; i < r; i++) {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        edges.push_back({n1 - 1, n2 - 1, w});
    }
    
    std::cout << calculateMaximumObtain(edges, itemQuantity, m) << '\n';
    
    return 0;
}
