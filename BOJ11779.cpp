#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

// Solving BOJ 11779

const int inf = 2000000000;

struct node
{
    int dst;
    int cost;
};

std::pair< int*, int* > dijkstra_dist(std::vector<node>* graph, int source, int V)
{
    std::priority_queue< std::pair<int, int> > pq;
    
    int* dist = new int[V + 1];
    int* prev = new int[V + 1];
    
    for(int i = 1; i <= V; i++)
        dist[i] = inf;
    dist[source] = 0;
    
    pq.push({-dist[source], source});
    // Priority Queue seems to set the priorities of elements by the first item.
    // Therefore, costs should be the first item of each element.
    
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
                prev[curdst] = u.second;
            }
        }
    }
    
    return {dist, prev};
}

int main(void)
{
    std::vector<node> Graph[20001];
    
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
    
    std::pair< int*, int* > distance = dijkstra_dist(Graph, src, v);
    //printf("%d to %d: ", src, i);
    if (distance.first[dst] < inf)
    {
        printf("%d\n", distance.first[dst]);
        
        // pushing the previous on the temp stack
        std::stack<int> prevStack;
        int pr = dst;
        while(true)
        {
            prevStack.push(pr);
            if(pr == src) break;
            pr = distance.second[pr];
        }
            
        printf("%d\n", prevStack.size());
            
        while(!prevStack.empty())
        {
            printf("%d ", prevStack.top());
            prevStack.pop();
        }
    }
    else printf("Not available\n");
    
    putchar('\n');
    
    // never forget to delete the allocated
    delete distance.first;
    delete distance.second;
    
    return 0;
}
