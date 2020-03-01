#include <iostream>
#include <cstdio>

// solving BOJ 14501

int n;              // the number of consult days
int t[15], p[15];   // t[]: consulting length, p[]: reward of the consult

int calcMaxReward(const int start)
{
    int maxReward = 0;
    
    for(int i = start; i < n; i++)
    {
        int curReward = 0;
        
        // if this consulting length doesn't exceed remaining days,
        // get the current reward and calculate next rewards
        
        if(i + t[i] <= n) 
        {
            curReward += p[i];
        }
        else
        {
            continue;
        }
        
        curReward += calcMaxReward(i + t[i]);
        
        if(curReward > maxReward)
        {
            maxReward = curReward;
        }
    }
    
    return maxReward;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &t[i], &p[i]);
    }
    
    printf("%d\n", calcMaxReward(0));
    
    return 0;
}
