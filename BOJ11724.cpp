#include <iostream>
#include <vector>
#include <queue>

// solving BOJ 11724

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector< std::vector<int> > graph(n, std::vector<int>());
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        
        std::cin >> u >> v;
        u--;
        v--;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    std::vector<bool> visited(n, false);
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            std::queue<int> next;
            next.push(i);
            
            while(!next.empty())
            {
                int cur = next.front();
                next.pop();
                
                if(visited[cur])
                {
                    continue;
                }
                
                visited[cur] = true;
                
                for(int j = 0; j < graph[cur].size(); j++)
                {
                    if(!visited[graph[cur][j]])
                    {
                        next.push(graph[cur][j]);
                    }
                }
            }
            
            result++;
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
