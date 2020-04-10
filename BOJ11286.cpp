#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// Solving BOJ 11286

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int input;
    
    // first: absolute value of an element, second: negative value flag
    // std heap sorts in descending order
    std::vector< std::pair<int,int> > v;
    std::make_heap(v.begin(), v.end());
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        
        // input == 0 -> pop an element that has the lowest absolute value
        // else -> push an element to queue
        
        if(input == 0)
        {
            if(v.size() == 0)
            {
                // if empty, print 0
                printf("0\n");
                continue;
            }
            else
            {
                printf("%d\n", -v.front().first * (-v.front().second));
                std::pop_heap(v.begin(), v.end());
                v.pop_back();
            }
        }
        else
        {
            // making std heap sort in ascending order
            v.push_back({-std::abs(input), -(input < 0 ? -1 : 1)});
            std::push_heap(v.begin(), v.end());
        }
    }
    
    return 0;
}
