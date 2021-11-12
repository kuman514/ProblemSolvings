#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Solving BOJ 1197

struct Vertex {
    int from;
    int to;
    int weight;
};

bool moreWeight(Vertex& a, Vertex& b) {
    if (a.weight != b.weight) {
        return (a.weight < b.weight);
    }
    
    return (a.to < b.to);
}

class myComparison {
    public:
        bool operator() (Vertex& a, Vertex& b) const {
            if (a.weight != b.weight) {
                return (a.weight > b.weight);
            }
            
            return (a.to > b.to);
        }
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    // Get sizes
    int v, e;
    std::cin >> v >> e;
    
    // Get edges
    std::vector< std::vector<Vertex> > graph(v, std::vector<Vertex>());
    for (int i = 0; i < e; i++) {
        int src, dst, cost;
        std::cin >> src >> dst >> cost;
        
        src--;
        dst--;
        
        graph[src].push_back({src, dst, cost});
        graph[dst].push_back({dst, src, cost});
    }
    
    // Sort all edges of each vertex by their weight
    for (int i = 0; i < v; i++) {
        std::sort(graph[i].begin(), graph[i].end(), moreWeight);
    }
    
    // Using Prim MST Algorithm
    int totalCost = 0;
    std::vector<bool> visited(v, false);
    std::priority_queue< Vertex, std::vector<Vertex>, myComparison > next;
    
    next.push({-1, 0, 0});
    while (!next.empty()) {
        Vertex cur = next.top();
        next.pop();
        
        if (visited[cur.to]) {
            continue;
        }
        
        visited[cur.to] = true;
        totalCost += cur.weight;
        
        // Find next
        for (int i = 0; i < graph[cur.to].size(); i++) {
            if (visited[graph[cur.to][i].to]) {
                continue;
            }
            
            next.push({cur.to, graph[cur.to][i].to, graph[cur.to][i].weight});
        }
    }
    
    std::cout << totalCost << '\n';

    return 0;
}
