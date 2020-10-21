#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

// Solving BOJ 7568

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // Input
    std::vector< std::pair<int, int> > weightAndHeight;
    for(int i = 0; i < n; i++)
    {
        int w, h;
        std::cin >> w >> h;
        
        weightAndHeight.push_back(std::pair<int, int>(w, h));
    }
    
    // Compare
    std::vector<int> result;
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            
            if(weightAndHeight[i].first < weightAndHeight[j].first
               && weightAndHeight[i].second < weightAndHeight[j].second)
            {
                count++;
            }
        }
        
        result.push_back(count);
    }
    
    // Printing
    for(int i = 0; i < n; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
