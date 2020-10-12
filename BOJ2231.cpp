#include <iostream>
#include <cstdio>

// Solved BOJ 2231

int creator(int num)
{
    int result = num;
    while(num != 0)
    {
        result += (num % 10);
        num /= 10;
    }
    return result;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int tmpcr, i;
    for(i = 1; i < N; i++)
    {
        tmpcr = creator(i);
        if(tmpcr == N)
            break;
    }
    
    if(tmpcr != N) printf("0\n");
    else printf("%d\n", i);
    
    return 0;
}
