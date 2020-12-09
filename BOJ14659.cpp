#include <iostream>
#include <vector>

// Solving BOJ 14659

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    std::cin >> n;
    
    std::vector<int> height(n, 0);
    for(int i = 0; i < n; i++)
    {
        std::cin >> height[i];
    }
    
    // Count enemies eliminated
    int hanzo = height[0];
    int maximum = 0;
    int current = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(height[i] > hanzo)
        {
            hanzo = height[i];
            
            if(maximum < current)
            {
                maximum = current;
            }
            
            current = 0;
        }
        else
        {
            current++;
        }
    }
    
    if(maximum < current)
    {
        maximum = current;
    }
    
    std::cout << maximum << '\n';

    return 0;
}
