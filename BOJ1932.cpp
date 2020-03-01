#include <iostream>
#include <cstdio>

// solving BOJ 1932

int main(void)
{
    int sum[500] = {0,};        // DYNAMIC PROGRAMING: saves only the biggest sum
    int n;                      // height of the triangle
    scanf("%d", &n);
    
    int input[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            // input a number
            scanf("%d", &input[j]);
            
            if(j == 0)
            {
                // very left of the current line
                input[j] += sum[j];
            }
            else if(j == i)
            {
                // very right of the current line
                input[j] += sum[j-1];
            }
            else
            {
                // choose and add a bigger value
                input[j] += std::max(sum[j-1], sum[j]);
            }
        }
        
        for(int k = 0; k <= i; k++)
        {
            // copy to the sum array
            sum[k] = input[k];
        }
    }
    
    int highest = 0;
    for(int i = 0; i < n; i++)
    {
        if(highest < sum[i])
            highest = sum[i];
    }
    
    printf("%d\n", highest);
    
    return 0;
}
