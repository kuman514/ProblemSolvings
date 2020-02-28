#include <iostream>
#include <cstdio>
#include <cmath>

// solving BOJ 4172

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    // x[0] = 1
    // x[i] = x[floor(i - sqrt(i))] + x[floor(ln(i))] + x[floor(i * (sin(i) ** 2))]
    
    // assume that 0 <= a,b <= 1000000
    // (x[a] + x[b]) % 1000000 == (x[a] % 1000000) + (x[b] % 1000000)
    // therefore, we can define x[i] as (x[i] % 1000000)
    
    // floor value of a >= 0 equals to integer value of a
    
    int x[1000001];
    x[0] = 1;
    
    // init
    for(int i=1; i<=1000000; i++)
    {
        x[i] = (x[(int)(i - sqrt(i))] + x[(int)(log(i))] + x[(int)(i * sin(i) * sin(i))]) % 1000000;
    }
    
    int input;
    while(true)
    {
        std::cin >> input;
        if(input == -1) 
        {
            // exit
            break;
        }
        std::cout << x[input] << '\n';
    }
    
    return 0;
}
