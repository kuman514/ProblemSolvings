#include <iostream>
#include <vector>

// solving BOJ 11727

/*
(n == r || r == 0) => 1
n_COMBINATION_r = (n - 1)_COMBINATION_(r - 1) + (n - 1)_COMBINATION_(r)

[WHILE n - 2 * i >= 0]
(s * (n - 2 * i) + d * i) * (n - i)_COMBINATION_i
=> (2 ** i) * (n - i)_COMBINATION_i
[i++]
*/

class combination
{
    private:
        std::vector< std::vector<int> > combinationTable;
        int divisor;
    
    public:
        combination(const int n, const int D):
            combinationTable
                (std::vector< std::vector<int> >(n + 1, std::vector<int>(n + 1, 0))),
            divisor
                (D)
        
        {
            for(int i = 0; i <= n; i++)
            {
                for(int j = 0; j <= i; j++)
                {
                    if(j == 0 || j == i)
                    {
                        combinationTable[i][j] = 1;
                    }
                    else
                    {
                        combinationTable[i][j] = (combinationTable[i - 1][j - 1] % divisor)
                                                 + (combinationTable[i - 1][j] % divisor);
                        combinationTable[i][j] %= divisor;
                    }
                }
            }
        }
        int c(const int n, const int r)
        {
            return combinationTable[n][r];
        }
};

class pow2
{
    private:
        std::vector<int> table;
        int divisor;
    
    public:
        pow2(const int n, const int D):
            table(std::vector<int>(n + 1, 1)), divisor(D)
        {
            for(int i = 1; i <= n; i++)
            {
                table[i] = (table[i - 1] * 2) % divisor;
            }
        }
        int p2(const int n)
        {
            return table[n];
        }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    int result = 0;
    combination c(n, 10007);
    pow2 p2(n, 10007);
    
    int i = 0;
    while(n - (2 * i) >= 0)
    {
        result += ((p2.p2(i) % 10007) * (c.c(n - i, i) % 10007));
        result %= 10007;
        i++;
    }
    
    std::cout << result << '\n';

    return 0;
}
