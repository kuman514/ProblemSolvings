#include <iostream>
#include <cstdio>

// Solving BOJ 2749

int main(void)
{
    // Using Pisano Period
    // fibo(n) % M = fibo(n % period) % M
    // M: 1000000 = 10^6 -> k=6
    // period: 15 * 10^(k-1) -> 15 * 10^5 = 150000
    
    int fibo[1500000] = {0,1};
    long long int n;
    scanf("%lld", &n);
    int reach = n % 1500000;

    for(int i = 2; i <= reach; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000;
    }

    printf("%d\n", fibo[reach]);
    
    return 0;
}
