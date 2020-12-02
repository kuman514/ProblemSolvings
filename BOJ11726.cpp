#include <iostream>
#include <vector>

// Solving BOJ 11726

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    /*
    n = 1 :: ways = 1
    n = 2 :: ways = 2
    n = 3 :: ways = 3
    n = 4 :: ways = 5
    n = 5 :: ways = 8
    .
    .
    .
    n :: ways = fibonacci(n)
    
    Therefore, we will use fibonacci memoization to solve this
    */
    
    std::vector<int> fibo(2, 1);
    for(int i = 2; i <= n; i++)
    {
        fibo.push_back((fibo[i - 1] + fibo[i - 2]) % 10007);
    }
    
    std::cout << fibo[n] << '\n';

    return 0;
}
