#include <iostream>
#include <sstream>

// solving BOJ 2741 in the shortest time (4ms)

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::stringstream ss;
    for(int i = 1; i <= n; ++i)
    {
        ss << i << '\n';
    }
    
    std::cout << ss.str();
    return 0;
}
