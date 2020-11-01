#include <iostream>
#include <string>

// solving BOJ 15829

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::string str;
    std::cin >> str;
    
    long long result = 0LL;
    
    for(int i = 0; i < n; i++)
    {
        long long tmp = static_cast<long long>(str[i] - 'a') + 1;
        
        for(int j = 0; j < i; j++)
        {
            tmp = (tmp * 31) % 1234567891;
        }
        
        result = (result + tmp) % 1234567891;
    }
    
    std::cout << result << '\n';
    
    return 0;
}
