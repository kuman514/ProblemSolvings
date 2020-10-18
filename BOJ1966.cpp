#include <iostream>
#include <cstdio>
#include <utility>
#include <deque>
#include <vector>
#include <algorithm>

// Solving BOJ 1966

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int cases = 0;
    std::cin >> cases;
    
    for(int curCase = 0; curCase < cases; curCase++)
    {
        int n = 0, target = 0;
        std::cin >> n >> target;
        
        std::deque< std::pair<int, int> > printQueue;
        for(int i = 0; i < n; i++)
        {
            int priority = 0;
            std::cin >> priority;
            printQueue.push_back(std::pair<int, int>(i, priority));
        }
        
        int printed = 1;
        while(!printQueue.empty())
        {
            // first: index
            // second: priority
            
            std::pair<int, int> current = printQueue.front();
            printQueue.pop_front();
            bool hasHigher = false;
            
            // Seek higher priority
            for(int i = 0; i < printQueue.size() && !hasHigher; i++)
            {
                if(current.second < printQueue[i].second)
                {
                    printQueue.push_back(current);
                    hasHigher = true;
                    break;
                }
            }
            
            if(!hasHigher && current.first == target)
            {
                std::cout << printed << '\n';
                break;
            }
            else if(!hasHigher)
            {
                printed++;
            }
        }
    }
    
    return 0;
}
