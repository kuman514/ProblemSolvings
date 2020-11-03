#include <iostream>
#include <cstdio>
#include <queue>

// Solving BOJ 2606

int main(void)
{
    int points, vertexes;
    scanf("%d", &points);
    scanf("%d", &vertexes);
    
    char graph[points + 1][points + 1] = {0,};
    int r, c;
    for(int i = 0; i < vertexes; i++)
    {
        scanf("%d %d", &r, &c);
        graph[r][c] = 1;
        graph[c][r] = 1;
    }
    
    std::queue<int> infected;
    infected.push(1);
    
    int cur;
    char zombie[points + 1] = {0,};
    while(!infected.empty())
    {
        cur = infected.front();
        zombie[cur] = 1;
        
        for(int i = 1; i <= points; i++)
        {
            if(graph[cur][i] == 1 && zombie[i] == 0)
                infected.push(i);
        }
        
        infected.pop();
    }
    
    int z = 0;
    for(int i = 1; i <= points; i++)
        z += zombie[i];
    
    printf("%d\n", z - 1);
    
    return 0;
}
