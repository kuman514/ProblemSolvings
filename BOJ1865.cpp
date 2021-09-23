#include <iostream>
#include <vector>

// Solving BOJ 1865

const long long INF = 500 * 10000 + 1;

struct edge {
    int src;
    int dst;
    int weight;
};

bool canIGetNegativeCycle(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, w;
    std::cin >> n >> m >> w;
    std::vector<edge> edges;
    
    // Get input: roads
    for (int i = 0; i < m; i++) {
        int s, e, t;
        std::cin >> s >> e >> t;
        edges.push_back({s - 1, e - 1, t});
        edges.push_back({e - 1, s - 1, t});
    }
    
    // Get input: wormholes
    for (int i = 0; i < w; i++) {
        int s, e, t;
        std::cin >> s >> e >> t;
        edges.push_back({s - 1, e - 1, -t});
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
            
            if (vertexDist[v] > vertexDist[u] + uv.weight) {
                vertexDist[v] = vertexDist[u] + uv.weight;
                
                // Negative weight cycle
                if (i == n - 1) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tc;
    std::cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        std::cout << (canIGetNegativeCycle() ? "YES\n" : "NO\n");
    }

    return 0;
}
