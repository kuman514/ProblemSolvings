#include <iostream>

// Solving BOJ 2096

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // Get input
    int cost[n][3];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> cost[i][j];
        }
    }
    
    // Calculate max cost
    int maxcost[3];
    for(int i = 0; i < 3; i++)
    {
        maxcost[i] = cost[0][i];
    }
    
    for(int i = 1; i < n; i++)
    {
        int tmp[3] = {0,};
        
        for(int j = 0; j < 3; j++)
        {
            switch(j)
            {
                case 0:
                    tmp[j] = cost[i][j] + std::max(maxcost[0], maxcost[1]);
                    break;
                case 1:
                    tmp[j] = cost[i][j] + std::max(maxcost[0], std::max(maxcost[1], maxcost[2]));
                    break;
                case 2:
                    tmp[j] = cost[i][j] + std::max(maxcost[1], maxcost[2]);
                    break;
            }
        }
        
        for(int j = 0; j < 3; j++)
        {
            maxcost[j] = tmp[j];
        }
    }
    
    // Calculate min cost
    int mincost[3];
    for(int i = 0; i < 3; i++)
    {
        mincost[i] = cost[0][i];
    }
    
    for(int i = 1; i < n; i++)
    {
        int tmp[3] = {0,};
        
        for(int j = 0; j < 3; j++)
        {
            switch(j)
            {
                case 0:
                    tmp[j] = cost[i][j] + std::min(mincost[0], mincost[1]);
                    break;
                case 1:
                    tmp[j] = cost[i][j] + std::min(mincost[0], std::min(mincost[1], mincost[2]));
                    break;
                case 2:
                    tmp[j] = cost[i][j] + std::min(mincost[1], mincost[2]);
                    break;
            }
        }
        
        for(int j = 0; j < 3; j++)
        {
            mincost[j] = tmp[j];
        }
    }
    
    // Result
    int maximum = -1, minimum = 1000000;
    for(int i = 0; i < 3; i++)
    {
        if(maximum < maxcost[i]) maximum = maxcost[i];
        if(minimum > mincost[i]) minimum = mincost[i];
    }
    
    std::cout << maximum << ' ' << minimum << '\n';

    return 0;
}
