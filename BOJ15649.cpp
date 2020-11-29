#include <iostream>
#include <cstdio>

// Solving BOJ 15649

int permutation[8];
int n, m;

void setPermutaions(const int pos)
{
    permutation[pos] = 1;
    bool duplicated = false;
    
    while(permutation[pos] <= n)
    {
        duplicated = false;
        
        for(int i = 0; i < pos; i++)
        {
            if(permutation[i] == permutation[pos])
            {
                duplicated = true;
                break;
            }
        }
        
        if(!duplicated)
        {
            if(pos == m - 1)
            {
                for(int i = 0; i < m; i++)
                {
                    printf("%d ", permutation[i]);
                }
                printf("\n");
            }
            else
            {
                setPermutaions(pos + 1);
            }
        }
        
        permutation[pos]++;
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    setPermutaions(0);
    
    return 0;
}
