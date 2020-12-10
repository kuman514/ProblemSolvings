#include <iostream>
#include <cstdio>
#include <numeric>

// Solving BOJ 1850

long long MyGCD()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    return std::gcd(a, b);
}

int main(void)
{
    long long count = MyGCD();
    for(long long i = 0ll; i < count; i++)
        putchar('1');
    return 0;
}
