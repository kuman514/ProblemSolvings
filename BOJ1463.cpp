#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

// Solving BOJ 1463

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // first: the input number, second: counts operated
    std::queue< std::pair<int, int> > npq;
    npq.push({n, 0});
    
    while(!npq.empty())
    {
        std::pair<int, int> tmpPair = npq.front();
        npq.pop();
        
        if(tmpPair.first < 1)
            continue;
        
        if(tmpPair.first == 1)
        {
            std::cout << tmpPair.second << std::endl;
            break;
        }
        
        if(tmpPair.first % 3 == 0)
        {
            npq.push({tmpPair.first / 3, tmpPair.second + 1});
        }
        
        if(tmpPair.first % 2 == 0)
        {
            npq.push({tmpPair.first / 2, tmpPair.second + 1});
        }
        
        npq.push({tmpPair.first - 1, tmpPair.second + 1});
    }
    
    return 0;
}
