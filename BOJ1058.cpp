#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// solving BOJ 1058

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // Get input
    std::vector< std::vector<int> > relationship(n, std::vector<int>());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char input;
            std::cin >> input;
            
            if(input == 'Y')
            {
                relationship[i].push_back(j);
                relationship[j].push_back(i);
            }
        }
    }
    
    // Count the number of friends who knows them
    int maxknow = 0;
    for(int i = 0; i < n; i++)
    {
        std::vector<bool> checked(n, false);
        int knowers = 0;
        
        checked[i] = true;
        
        // Paint friends using brute force
        for(int j = 0; j < relationship[i].size(); j++)
        {
            if(!checked[relationship[i][j]])
            {
                checked[relationship[i][j]] = true;
                knowers++;
            }
            
            for(int k = 0; k < relationship[relationship[i][j]].size(); k++)
            {
                if(!checked[relationship[relationship[i][j]][k]])
                {
                    checked[relationship[relationship[i][j]][k]] = true;
                    knowers++;
                }
            }
        }
        
        if(knowers > maxknow)
        {
            maxknow = knowers;
        }
    }
    
    std::cout << maxknow << '\n';
    
    return 0;
}
