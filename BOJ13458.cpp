#include <iostream>
#include <cstdio>

// solving BOJ 13458

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    int capacity[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> capacity[i];
    }
    
    // b - number of people main supervisor can control
    // c - number of people sub supervisor can control
    int b, c;
    std::cin >> b >> c;
    
    // (capacity * n) / (b or c) may exceed the range of int
    long long result = 0ll;
    
    for(int i = 0; i < n; i++)
    {
        // 1 main supervisor required
        result += 1;
        
        if(capacity[i] - b > 0)
        {
            // we need a sub supervisor per c other people
            result += (capacity[i] - b) / c;
            
            // if there're other people not controlled
            // we need 1 more sub supervisor
            if((capacity[i] - b) % c > 0)
            {
                result += 1;
            }
        }
    }
    
    std::cout << result << '\n';
    
    return 0;
}