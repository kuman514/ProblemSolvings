#include <iostream>
#include <vector>

// Solving BOJ 1389

int FloydWarshall(std::vector< std::vector<int> >& graph)
{
    /*
    let dist be a |V| × |V| array of minimum distances initialized to ∞

    for each edge (u,v)
        dist[u][v] ← w(u,v)

    for each vertex v
        dist[v][v] ← 0

    for k from 1 to |V|
        for i from 1 to |V|
            for j from 1 to |V|
                if dist[i][j] > dist[i][k] + dist[k][j]
                    dist[i][j] ← dist[i][k] + dist[k][j]
                end if
    */
    
    // Initialize array
    const int INF = 500001;
    std::vector< std::vector<int> > cost(graph.size(), std::vector<int>(graph.size(), INF));
    
    // Edge value
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            cost[i][graph[i][j]] = 1;
        }
    }
    
    // Own vertex
    for(int i = 0; i < cost.size(); i++)
    {
        cost[i][i] = 0;
    }
    
    // Calculate
    for(int k = 0; k < cost.size(); k++)
    {
        for(int i = 0; i < cost.size(); i++)
        {
            for(int j = 0; j < cost.size(); j++)
            {
                if(cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    /*
    // Debug print cost
    for(int i = 0; i < cost.size(); i++)
    {
        for(int j = 0; j < cost.size(); j++)
        {
            std::cout << cost[i][j] << ' ';
        }
        
        std::cout << '\n';
    }
    */
    
    // Calculate each Kevin Bacon Value
    int lowest = 2147483647;
    int index = -1;
    std::vector<int> kv(cost.size(), 0);
    for(int i = 0; i < cost.size(); i++)
    {
        for(int j = 0; j < cost.size(); j++)
        {
            kv[i] += cost[i][j];
        }
        
        if(kv[i] < lowest)
        {
            lowest = kv[i];
            index = i;
        }
    }
    
    return index + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector< std::vector<int> > weight(n, std::vector<int>());
    
    // Get input
    for(int i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        
        from--;
        to--;
        
        weight[from].push_back(to);
        weight[to].push_back(from);
    }
    
    std::cout << FloydWarshall(weight) << '\n';

    return 0;
}
