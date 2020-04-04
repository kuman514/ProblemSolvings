#include <iostream>
#include <cstdio>

// solving BOJ 1654

int main(void)
{
    int k, n;
    scanf("%d %d", &k, &n);
    
    int cable[k];
    long long sum = 0ll;
    for(int i=0; i<k; i++)
    {
        scanf("%d", &cable[i]);
        sum += cable[i];
    }
    
    // This solution uses the Binary Search.
    long long shorter = 1ll, longer = sum / n;
    long long curlen;
    
    while(shorter <= longer)
    {
        curlen = (shorter + longer) / 2;
        
        long long tmpsum = 0;
        for(int i=0; i<k; i++)
        {
            tmpsum += cable[i] / curlen;
        }
        
        if(tmpsum < n)            // if longer curlen
        {
            // make curlen shorter
            longer = curlen - 1;
        }
        else if(tmpsum >= n)      // if shorter curlen
        {
            // make curlen longer
            shorter = curlen + 1;
        }
    }
    
    printf("%lld\n", longer);
    
    return 0;
}
