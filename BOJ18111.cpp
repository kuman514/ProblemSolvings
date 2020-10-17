#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

// Solving BOJ 18111

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m, b;
    int highest = 0;
    
    std::cin >> n >> m >> b;
    std::vector<int> field(n * m, 0);
    
    for(int i = 0; i < field.size(); i++)
    {
        std::cin >> field[i];
        
        if(highest < field[i])
        {
            highest = field[i];
        }
    }
    
    // Calculate
    int curHeight = highest;
    int minimum = 1000000000;
    int finalHeight = 0;
    
    while(curHeight >= 0)
    {
        int reqBlocks = 0;
        int conBlocks = b;
        int reqTime = 0;
        
        for(int i = 0; i < field.size(); i++)
        {
            if(field[i] > curHeight)
            {
                reqTime += (field[i] - curHeight) * 2;
                conBlocks += field[i] - curHeight;
            }
            else if(field[i] < curHeight)
            {
                reqTime += curHeight - field[i];
                reqBlocks += curHeight - field[i];
            }
        }
        
        // Qualify? (reqBlocks <= conBlocks)
        if(reqBlocks <= conBlocks)
        {
            if(minimum > reqTime)
            {
                minimum = reqTime;
                finalHeight = curHeight;
            }
            else if(minimum == reqTime && finalHeight < curHeight)
            {
                minimum = reqTime;
                finalHeight = curHeight;
            }
        }
        
        curHeight--;
    }
    
    // Print result
    std::cout << minimum << ' ' << finalHeight << '\n';
    
    return 0;
}
