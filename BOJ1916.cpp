#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

const int inf = 2000000000;

struct node
{
    int dst;
    int cost;
};

int* dijkstra_dist(std::vector<node>* graph, int source, int V)
{
    std::priority_queue< std::pair<int, int> > pq;
    int* dist = new int[V + 1];
    
    for(int i = 1; i <= V; i++)
        dist[i] = inf;
    dist[source] = 0;
    
    pq.push({-dist[source], source});
    // Priority Queue seems to set the priorities of elements by the first item.
    // Therefore, costs should be the first item of each element.
    
    while(!pq.empty())
    {
        std::pair<int, int> u = pq.top();
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
    std::vector<node> Graph[1001];
    
    int v, e;
    scanf("%d", &v);
    scanf("%d", &e);
    
    int from, to, c;
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &from, &to, &c);
        Graph[from].push_back(node{to, c});
    }
    
    int src, dst;
    scanf("%d %d", &src, &dst);
    
    int* distance = dijkstra_dist(Graph, src, v);
    
    if (distance[dst] < inf) printf("%d\n", distance[dst]);
    else printf("INF\n");
    
    delete[] distance;
    
    return 0;
}
