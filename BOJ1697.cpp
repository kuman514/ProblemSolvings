#include <iostream>
#include <queue>
#include <utility>

// Solving BOJ 1697

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k;
    std::cin >> n >> k;
    
    bool visited[100001] = {false,};
    
    if(n >= k)
    {
        std::cout << n - k << '\n';
        return 0;
    }
    
    // first: time, second: position
    std::queue< std::pair<int, int> > progress;
    progress.push({0, n});
    
    while(!progress.empty())
    {
        std::pair<int, int> cur = progress.front();
        progress.pop();
        
        if(cur.second < 0 || cur.second > 100000) continue;
        if(visited[cur.second]) continue;
        
        visited[cur.second] = true;
        
        // Has Subin got her brother?
        if(cur.second == k)
        {
            std::cout << cur.first << '\n';
            return 0;
        }
        
        // Next information
        progress.push({cur.first + 1, cur.second - 1});
        progress.push({cur.first + 1, cur.second + 1});
        progress.push({cur.first + 1, cur.second * 2});
    }
    
    return 0;
}
