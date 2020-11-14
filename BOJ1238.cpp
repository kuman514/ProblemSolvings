#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

// Solving BOJ 1238

const int inf = 2000000000;

struct node
{
    int dst;
    int cost;
};

int* dijkstra_dist(std::vector<node>* graph, int source, int V)
{
    std::priority_queue< std::pair<int,int> > pq;
    int* dist = new int[V + 1];
    
    for(int i = 1; i <= V; i++)
        dist[i] = inf;
    dist[source] = 0;
    
    pq.push({-dist[source], source});
    
    while(!pq.empty())
    {
        std::pair<int,int> u = pq.top();
        pq.pop();
        
        int neighbors = graph[u.second].size();
        for(int i = 0; i < neighbors; i++)
        {
            int alt = dist[u.second] + graph[u.second][i].cost;
            int curdst = graph[u.second][i].dst;
            if(alt < dist[curdst])
            {
                dist[curdst] = alt;
                pq.push({-dist[curdst], curdst});
            }
        }
    }
    
    return dist;
}

int main(void)
{
    std::vector<node> GRAPH[1001];
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);
    
    // Get input
    for(int i = 0; i < M; i++)
    {
        int src, dst, c;
        scanf("%d %d %d", &src, &dst, &c);
        GRAPH[src].push_back({dst, c});
    }
    
    int cost[N + 1] = {0,};
    
    // Calculate shortest distance for going back from X
    int* dist_X = dijkstra_dist(GRAPH, X, N);
    
    for(int i = 1; i <= N; i++)
    {
        // Calculate shortest distance for going to X
        int* dist_i = dijkstra_dist(GRAPH, i, N);
        
        // Cost for i = Dist i to X + Dist X to i
        cost[i] = dist_i[X] + dist_X[i];
        
        delete dist_i;
    }
    
    delete dist_X;
    
    // Result print
    int most = 0;
    for(int i = 1; i <= N; i++)
    {
        if(cost[i] > most)
            most = cost[i];
    }
    
    printf("%d\n", most);
    
    return 0;
}
