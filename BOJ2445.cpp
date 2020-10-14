#include <iostream>
#include <cstdio>
#include <cmath>

// solving BOJ 2445

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin >> n;
    
    int scope = 2 * n;
    for(int i = 1; i < scope; i++)
    {
        for(int j = 1; j <= scope; j++)
        {
            if(std::abs(n - j) <= std::abs(n - i))
            {
                if(std::abs(n - j) == std::abs(n - i) && j <= n)
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << ' ';
                }
            }
            else
            {
                std::cout << '*';
            }
        }
        
        std::cout << '\n';
    }
    
    return 0;
}
