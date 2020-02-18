#include <iostream>
#include <cstdio>
#include <queue>

// solving BOJ 17144

// diffusion information
struct diff
{
    int row;        // row position
    int col;        // column position
    int deg;        // degree (amount of the dust to diffuse)
};

int main(void)
{
    // row span, column span, time elapsed
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    
    // dust pollution map
    int pol[r][c];
    
    // position of the purifier
    int purifier[2][2], pPos = 0;
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            // dust map information input
            scanf("%d", &pol[i][j]);
            
            // purifier input
            if(pol[i][j] == -1)
            {
                purifier[pPos][0] = i;
                purifier[pPos][1] = j;
                pPos++;
            }
        }
    }
    
    for(int elap = 0; elap < t; elap++)
    {
        // check dust that will diffuse
        std::queue<diff> dq;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                // check diffusion only if dust exists
                if(pol[i][j] > 0)
                {
                    int arc = pol[i][j] / 5;
                    
                    // up
                    if(i - 1 >= 0 && pol[i - 1][j] != -1)
                    {
                        dq.push({i - 1, j, arc});
                        pol[i][j] -= arc;
                    }
                    
                    // down
                    if(i + 1 < r && pol[i + 1][j] != -1)
                    {
                        dq.push({i + 1, j, arc});
                        pol[i][j] -= arc;
                    }
                    
                    // left
                    if(j - 1 >= 0 && pol[i][j - 1] != -1)
                    {
                        dq.push({i, j - 1, arc});
                        pol[i][j] -= arc;
                    }
                    
                    // right
                    if(j + 1 < c && pol[i][j + 1] != -1)
                    {
                        dq.push({i, j + 1, arc});
                        pol[i][j] -= arc;
                    }
                }
            }
        }
        
        // diffusion
        diff tmpdf;
        while(!dq.empty())
        {
            tmpdf = dq.front();
            dq.pop();
            
            pol[tmpdf.row][tmpdf.col] += tmpdf.deg;
        }
        
        // upper side purification
        int rPos = purifier[0][0], cPos = purifier[0][1] - 1;
        while(cPos - 1 >= 0)
        {
            pol[rPos][cPos] = pol[rPos][cPos - 1];
            cPos--;
        }
        
        cPos = 0;
        rPos--;
        
        while(rPos - 1 >= 0)
        {
            pol[rPos][cPos] = pol[rPos - 1][cPos];
            rPos--;
        }
        
        rPos = 0;
        
        while(cPos + 1 < c)
        {
            pol[rPos][cPos] = pol[rPos][cPos + 1];
            cPos++;
        }
        
        cPos = c - 1;
        
        while(rPos + 1 <= purifier[0][0])
        {
            pol[rPos][cPos] = pol[rPos + 1][cPos];
            rPos++;
        }
        
        rPos = purifier[0][0];
        
        while(cPos - 1 > purifier[0][1])
        {
            pol[rPos][cPos] = pol[rPos][cPos - 1];
            cPos--;
        }
        
        pol[rPos][cPos] = 0;
        
        // lower side purification
        rPos = purifier[1][0], cPos = purifier[1][1] - 1;
        while(cPos - 1 >= 0)
        {
            pol[rPos][cPos] = pol[rPos][cPos - 1];
            cPos--;
        }
        
        cPos = 0;
        rPos++;
        
        while(rPos + 1 < r)
        {
            pol[rPos][cPos] = pol[rPos + 1][cPos];
            rPos++;
        }
        
        rPos = r - 1;
        
        while(cPos + 1 < c)
        {
            pol[rPos][cPos] = pol[rPos][cPos + 1];
            cPos++;
        }
        
        cPos = c - 1;
        
        while(rPos - 1 >= purifier[1][0])
        {
            pol[rPos][cPos] = pol[rPos - 1][cPos];
            rPos--;
        }
        
        rPos = purifier[1][0];
        
        while(cPos - 1 > purifier[1][1])
        {
            pol[rPos][cPos] = pol[rPos][cPos - 1];
            cPos--;
        }
        
        pol[rPos][cPos] = 0;
        
        /*
        // for visualization
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                printf("%2d ", pol[i][j]);
            }
            printf("\n");
        }
        */
    }
    
    // print result
    // the sum of the purifier part = -2
    int result = 2;
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            result += pol[i][j];
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}