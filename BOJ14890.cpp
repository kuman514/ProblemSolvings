#include <iostream>
#include <cstdio>
#include <cmath>

// Solving BOJ 14890

int main(void)
{
    int n, l;
    scanf("%d %d", &n, &l);
    
    int map[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    int count = 0;
    
    // across
    for(int i = 0; i < n; i++)
    {
        bool failed = false;
        int finalDownSlide = -1;
        int finalUpSlide = -1;
        int j = 1;                  // because if j == 0, auto-pass.
        
        while(j < n)
        {
            // FAILS if height compared with the prev one differs >= 2
            if(std::abs(map[i][j - 1] - map[i][j]) >= 2)
            {
                failed = true;
            }
            // EXAMS if height is 1 LOWER than the prev one
            else if(map[i][j - 1] - map[i][j] == 1)
            {
                for(int k = 0; k < l; k++)
                {
                    if(j + k >= n)
                    {
                        failed = true;
                        break;
                    }
                    
                    if(map[i][j] != map[i][j + k])
                    {
                        failed = true;
                        break;
                    }
                }
                
                if(!failed)
                {
                    j += l - 1;
                    finalDownSlide = j;
                }
            }
            // EXAMS if height is 1 HIGHER than the prev one
            else if(map[i][j - 1] - map[i][j] == -1)
            {
                if(j-1 < finalDownSlide + l) failed = true;
                else if(j-1 < finalUpSlide + l) failed = true;
                else finalUpSlide = j - 1;
            }
            
            if(failed) break;
            
            j++;
        }
        
        if(!failed) count++;
    }
    
    // down
    for(int i = 0; i < n; i++)
    {
        bool failed = false;
        int finalDownSlide = -1;
        int finalUpSlide = -1;
        int j = 1;                  // because if j == 0, auto-pass.
        
        while(j < n)
        {
            // FAILS if height compared with the prev one differs >= 2
            if(std::abs(map[j - 1][i] - map[j][i]) >= 2)
            {
                failed = true;
            }
            // EXAMS if height is 1 LOWER than the prev one
            else if(map[j - 1][i] - map[j][i] == 1)
            {
                for(int k = 0; k < l; k++)
                {
                    if(j + k >= n)
                    {
                        failed = true;
                        break;
                    }
                    
                    if(map[j][i] != map[j + k][i])
                    {
                        failed = true;
                        break;
                    }
                }
                
                if(!failed)
                {
                    j += l - 1;
                    finalDownSlide = j;
                }
            }
            // EXAMS if height is 1 HIGHER than the prev one
            else if(map[j - 1][i] - map[j][i] == -1)
            {
                if(j - 1 < finalDownSlide + l) failed = true;
                else if(j - 1 < finalUpSlide + l) failed = true;
                else finalUpSlide = j - 1;
            }
            
            if(failed) break;
            
            j++;
        }
        
        if(!failed) count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
