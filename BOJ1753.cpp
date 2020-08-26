#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

// Solving BOJ 1753

const int inf = 2000000000;

/*
The Pseudo Code of Dijkstra Algorithm

function Dijkstra_Dist(Graph, Source):
 
    dist[source] ← 0                                // Initialize the distance from source to source, of course it's 0.

    create vertex set Q                             // Create Q, a set of nodes unvisited.

    for each vertex v in Graph:                     // Initialize all nodes in the Graph
        if v ≠ source:                              // Is node V not the source?
            dist[v] ← INFINITY                      // The distance from source to V is unknown. Therefore, consume it infinity.
        add v to Q                                  // And put node V initialized in set Q.

    // In short, initialize all nodes in the Graph and put them all in set Q.
      
    while Q is not empty:                           // While set Q is not empty...
        u ← vertex in Q with min dist[u]            // dist[source] = 0, will be selected in the first iteration. The U starts from the source.
        remove u from Q                             // Remove the visited node from set Q.
          
        for each neighbor v of u:                   // Calculate the distance from node U to each neighbor node.
            alt ← dist[u] + length(u, v)            // Alternative distance = Distance from source to node U + Distnace from node U to node V
                
            if alt < dist[v]:                       // If the alternative distance is shorter than the current distance from source to V,
                dist[v] ← alt                       // Set the distance from source to V into the alternative distance

    return dist[]                                   // Return the final values of the distance to each node.
*/

struct node
{
    int dst;
    int cost;
};

int* dijkstra_dist(std::vector<node>* graph, int source, int V)
{
    // Implementation of the Dijkstra Algorithm
    
    std::priority_queue< std::pair<int,int> > pq;
    int* dist = new int[V + 1];
    
    for(int i = 1; i <= V; i++)
        dist[i] = inf;
    dist[source] = 0;
    
    // In default, a Priority Queue sets the priorities of elements by the first item.
    // Therefore, costs should be the first item of each element.
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
    std::vector<node> Graph[20001];
    
    int v, e, src;
    scanf("%d %d", &v, &e);
    scanf("%d", &src);
    
    int from, to, c;
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &from, &to, &c);
        Graph[from].push_back(node{to, c});
    }
    
    int* distance = dijkstra_dist(Graph, src, v);
    for(int i=1; i<=v; i++)
    {
        if (distance[i] != inf) printf("%d\n", distance[i]);
        else printf("INF\n");
    }
    
    delete [] distance;
    
    return 0;
}
