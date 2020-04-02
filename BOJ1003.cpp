#include <iostream>
#include <cstdio>

// solving BOJ 1003

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int input[N], max=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &input[i]);
        if(input[i] > max) max = input[i];
    }
    
    // f_0 = 0, called only one 0.
    // f_1 = 1, called only one 1.
    int calls[max+1][2];
    calls[0][0] = 1, calls[0][1] = 0;
    calls[1][0] = 0, calls[1][1] = 1;
    
    // (n >= 2) -> number of calling 0 and 1 in f_n (= f_(n-1) + f_(n-2))
    // will equal to (number of calling 0 and 1 in f_(n-1) + number of calling 0 and 1 in f_(n-2))
    for(int i=2; i<=max; i++)
    {
        calls[i][0] = calls[i-1][0] + calls[i-2][0];
        calls[i][1] = calls[i-1][1] + calls[i-2][1];
    }
    
    for(int i=0; i<N; i++)
        printf("%d %d\n", calls[input[i]][0], calls[input[i]][1]);
    
    return 0;
}
