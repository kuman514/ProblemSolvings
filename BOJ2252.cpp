#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

// Solving BOJ 2252

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    std::queue<int> linked[32001];
    int linkcnt[32001] = {0,};
    
    for(int i = 0; i < m; i++)
    {
        int first, after;
        scanf("%d %d", &first, &after);
        
        linkcnt[after]++;
        linked[first].push(after);
    }
    
    // Topological Sort
    std::queue<int> q;
    
    for(int i = 1; i <= n; i++)
    {
        if(linkcnt[i] == 0)
            q.push(i);
    }
    
    int result[n] = {0,}, index = 0;
    for(int i = 0; i < n; i++)
    {
        int v = q.front();
        q.pop();
        
        result[index] = v;
        index++;
        
        while(!(linked[v].empty()))
        {
            int u = linked[v].front();
            linked[v].pop();
            linkcnt[u]--;
            
            if(linkcnt[u] == 0)
                q.push(u);
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);
    putchar('\n');
    
    return 0;
}
