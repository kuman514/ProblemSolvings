#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

// solving BOJ 4153

bool AllZero(std::vector<int>& inputs)
{
    for(int i = 0; i < inputs.size(); i++)
    {
        if(inputs[i] != 0)
            return false;
    }
    
    return true;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> input(3, 0);
    
    while(true)
    {
        for(int i = 0; i < 3; i++)
        {
            std::cin >> input[i];
        }
        
        if(AllZero(input)) break;
        
        std::sort(input.begin(), input.end());
        if(std::pow(input[0], 2) + std::pow(input[1], 2) == std::pow(input[2], 2))
        {
            std::cout << "right\n";
        }
        else
        {
            std::cout << "wrong\n";
        }
    }
    
    return 0;
}
