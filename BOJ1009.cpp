#include <iostream>
#include <cstdio>

// solving BOJ 1009

int main(void)
{
    // input
    int T;
    scanf("%d", &T);
    
    int a[T], b[T];
    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    
    // processing
    // the index of a computer that processes final data
    // = ((a ** b) % 10 == 0) ? (10) : ((a ** b) % 10)
    
    int result[T];
    
    // int pow value % 10 has patterns
    const int pattern[10][4] = {{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},
                                {5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
    
    for(int i=0; i<T; i++)
    {
        result[i] = pattern[a[i] % 10][(b[i]-1) % 4];
        if(result[i] == 0) result[i] = 10;
    }
    
    // printing result
    for(int i=0; i<T; i++)
    {
        printf("%d\n", result[i]);
    }
    
    return 0;
}
