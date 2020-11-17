#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

// Solving BOJ 1504

const int inf = (3 * 800 * 1000) + 1;

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
    std::vector<node> Graph[801];
    
    int n, e;
    scanf("%d %d", &n, &e);
    
    int from, to, c;
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &from, &to, &c);
        Graph[from].push_back(node{to, c});
        Graph[to].push_back(node{from, c});
    }
    
    int dst_1, dst_2;
    scanf("%d %d", &dst_1, &dst_2);
    
    // Calculate minimum cost to destination 1 and to destination 2
    int* dist_1 = dijkstra_dist(Graph, 1, n);
    int* dist_2 = dijkstra_dist(Graph, dst_1, n);
    int* dist_3 = dijkstra_dist(Graph, dst_2, n);
    
    // Destination 1 might be visited after destination 2
    // So we have two options
    // 1 -> dst_1 -> dst_2 -> n
    // 1 -> dst_2 -> dst_1 -> n
    long long ans1 = dist_1[dst_1] + dist_2[dst_2] + dist_3[n];
    long long ans2 = dist_1[dst_2] + dist_3[dst_1] + dist_2[n];
    
    if(ans1 >= inf && ans2 >= inf) printf("-1\n");
    else printf("%lld\n", (ans1 < ans2) ? ans1 : ans2);
    
    return 0;
}
