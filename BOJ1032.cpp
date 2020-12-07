#include <iostream>
#include <string>
#include <vector>

// Solving BOJ 1032

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::string pattern;
    std::cin >> pattern;
    
    for(int i = 0; i < n - 1; i++)
    {
        std::string current;
        std::cin >> current;
        
        for(int j = 0; j < current.length(); j++)
        {
            if(pattern[j] != current[j])
            {
                pattern[j] = '?';
            }
        }
    }
    
    std::cout << pattern;
    
    return 0;
}
