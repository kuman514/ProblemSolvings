#include <iostream>
#include <string>

// Solving BOJ 1439

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    std::string s;
    std::cin >> s;
    
    // Count which is less
    int area[2] = {0, 0};
    char current = 'x';
    for(int i = 0; i < s.length(); i++)
    {
        if(current != s[i])
        {
            area[s[i] - '0']++;
            current = s[i];
        }
    }
    
    // Show result
    std::cout << ((area[0] < area[1]) ? area[0] : area[1]) << '\n';

    return 0;
}
