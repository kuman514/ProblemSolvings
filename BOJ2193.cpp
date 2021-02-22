#include <iostream>
#include <vector>

// Solving BOJ 2193

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // The number of n-digit Ichinsu equals to fibonacci(n)
    std::vector<long long> fibonacci(n + 1, 0);
    fibonacci[1] = 1LL;
    for (int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    std::cout << fibonacci[n] << '\n';

    return 0;
}
