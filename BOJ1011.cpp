#include <iostream>
#include <cstdio>

// solving BOJ 1011

int main(void)
{
    int t;
    scanf("%d", &t);
    
    for(int i=0; i<t; i++)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        
        long long dist = y - x;
        
        if(dist == 0ll)
        {
            printf("0\n");
            continue;
        }
        
        /*
        dist: result - and why
        
         1: 1 - 1
         2: 2 - 1 1
         3: 3 - 1 1 1
         4: 3 - 1 2 1
         5: 4 - 1 2 1 1
         6: 4 - 1 2 2 1
         7: 5 - 1 2 1 2 1
         8: 5 - 1 2 2 2 1
         9: 5 - 1 2 3 2 1
        10: 6 - 1 2 2 2 2 1
        11: 6 - 1 2 3 2 2 1
        12: 6 - 1 2 3 3 2 1
        
         n: 2*f - 1 or 2*f
        2*f - 1 and 2*f repeat 2*(c**2) times
        
        */
        
        // using binary search to find the result way faster
        long long left = 0ll, right = 2147483647ll;
        long long count = (left + right) / 2;
        
        while(true)
        {
            long long countSQ = count * count;
            
            if(countSQ - count + 1 <= dist && dist <= countSQ)
            {
                printf("%lld\n", 2 * count - 1);
                break;
            }
            
            if(countSQ + 1 <= dist && dist <= countSQ + count)
            {
                printf("%lld\n", 2 * count);
                break;
            }
            
            // modify count
            if(dist < countSQ - count + 1)
            {
                right = count - 1;
                count = (left + right) / 2;
            }
            else if(countSQ + count < dist)
            {
                left = count + 1;
                count = (left + right) / 2;
            }
        }
    }
    
    return 0;
}