#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// solving BOJ 1931

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // first: start, second: end
    std::vector< std::pair<int, int> > meetings;
    
    for(int i = 0; i < n; i++)
    {
        int start, end;
        std::cin >> start >> end;
        meetings.push_back({start, end});
    }
    
    std::sort(meetings.begin(), meetings.end());
    
    // Counting maximum meetings
    // first: start, second: end
    std::pair<int, int> current(-1, -1);
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(meetings[i].first > current.second)
        {
            // If a start is later than the shortest end, count and replace
            count++;
            current = meetings[i];
        }
        else if(meetings[i].first == current.second)
        {
            // If a start is right after the shortest end, count
            count++;
            
            // and if this meeting doesn't stop right after start, update the end
            if(meetings[i].first < meetings[i].second)
            {
                current = meetings[i];
            }
        }
        else if(meetings[i].second < current.second)
        {
            // Replace to the new shortest end if a shorter end is found
            current = meetings[i];
        }
    }
    
    std::cout << count << '\n';
    
    return 0;
}
