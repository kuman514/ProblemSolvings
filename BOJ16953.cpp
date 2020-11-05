#include <iostream>
#include <queue>
#include <utility>

// Solving BOJ 16953

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long current, target;
    std::cin >> current >> target;
    
    // first: current value, second: current operation count
    std::queue< std::pair<long long, int> > next;
    next.push(std::pair<long long, int>(current, 0));
    
    while(!next.empty())
    {
        std::pair<long long, int> cur = next.front();
        next.pop();
        
        // Target found?
        if(cur.first == target)
        {
            std::cout << cur.second + 1 << '\n';
            return 0;
        }
        
        if(cur.first * 2 <= target)
        {
            next.push(std::pair<long long, int>(cur.first * 2, cur.second + 1));
        }
        
        if((cur.first * 10) + 1 <= target)
        {
            next.push(std::pair<long long, int>((cur.first * 10) + 1, cur.second + 1));
        }
    }

    std::cout << -1 << '\n';
    return 0;
}
