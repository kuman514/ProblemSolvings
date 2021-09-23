#include <iostream>
#include <vector>

// Solving BOJ 11657

const long long INF = 500 * 10000 + 1;

struct edge {
    int src;
    int dst;
    int weight;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m;
    std::cin >> n >> m;
    std::vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
    }
    
    // Bellman-Ford Solution
    
    // 1. Initialize vertices
    std::vector<long long> vertexDist(n, INF);
    vertexDist[0] = 0;
    
    // 2. Loop relaxing
    for (int i = 0; i < n; i++) {
        for (edge &uv : edges) {
            const int u = uv.src;
            const int v = uv.dst;
            
            // Don't calculate if the route to u doesn't exist
            if (vertexDist[u] == INF) {
                continue;
            }
            
            if (vertexDist[v] > vertexDist[u] + uv.weight) {
                vertexDist[v] = vertexDist[u] + uv.weight;
                
                // Negative weight cycle
                if (i == n - 1) {
                    std::cout << (-1) << '\n';
                    return 0;
                }
            }
        }
    }
    
    // 3. Print result
    for (int i = 0; i < vertexDist.size(); i++) {
        if (i == 0) {
            continue;
        }
        
        long long num = vertexDist[i];
        std::cout << ((num < INF) ? num : (-1)) << '\n';
    }

    return 0;
}
