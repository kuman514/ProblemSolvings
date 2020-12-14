#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// Solving BOJ 14889

int ourCrews[10];
int yourCrews[10];

int n;

int stats[20][20];
int minimum = 1000000000;

void selectCrew(const int i)
{
    ourCrews[i] = (i == 0) ? 0 : (ourCrews[i - 1] + 1);
    
    while(ourCrews[i] <= n + i)
    {
        if(i == n - 1)
        {
            for(int j = 0, ourIndex = 0, yourIndex = 0; j < 2 * n; j++)
            {
                if(j == ourCrews[ourIndex])
                {
                    ourIndex++;
                }
                else
                {
                    yourCrews[yourIndex] = j;
                    yourIndex++;
                }
            }
            
            // process =================================
            
            int ourScore = 0;
            int yourScore = 0;
            
            for(int j = 0; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    ourScore += stats[ourCrews[j]][ourCrews[k]];
                    yourScore += stats[yourCrews[j]][yourCrews[k]];
                }
            }
            
            minimum = std::min(std::abs(ourScore - yourScore), minimum);
            
            // end of process ==========================
        }
        else
        {
            selectCrew(i + 1);
        }
        
        ourCrews[i]++;
    }
}

int main(void)
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &stats[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            stats[i][j] += stats[j][i];
        }
    }
    
    n /= 2;
    selectCrew(0);
    
    printf("%d\n", minimum);
    
    return 0;
}
