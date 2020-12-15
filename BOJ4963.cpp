#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

// Solving BOJ 4963

int main(void)
{
    int c, r;
    
    scanf("%d %d", &c, &r);
    while(c != 0 && r != 0)
    {
        int input, landcnt = 0;
        bool land[r][c];
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                scanf("%d", &input);
                land[i][j] = (input == 1) ? true : false;
                landcnt += land[i][j] ? 1 : 0;
                //printf("%d ", land[i][j] ? 1 : 0);
            }
            //putchar('\n');
        }
        
        int count = 0;
        std::queue< std::pair<int,int> > q;
        while(landcnt > 0)
        {
            bool found = false;
            for(int i=0; i<r && !found; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(land[i][j])
                    {
                        count++;
                        //printf("land %d: (%d, %d)\n", count, j, i);
                        found = true;
                        q.push({i,j});
                        break;
                    }
                }
            }
            
            // search land connected
            while(!q.empty())
            {
                // first: row, second: column
                std::pair<int,int> curcoord = q.front();
                q.pop();
                
                // land check
                if(land[curcoord.first][curcoord.second])
                {
                    land[curcoord.first][curcoord.second] = false;
                    landcnt--;
                }
                else continue;
                
                // check a land around
                for(int i=-1; i<=1; i++)
                {
                    for(int j=-1; j<=1; j++)
                    {
                        if((0 <= curcoord.first+i && curcoord.first+i < r) && (0 <= curcoord.second+j && curcoord.second+j < c))
                        {
                            if(land[curcoord.first+i][curcoord.second+j])
                            {
                                //printf("land %d: (%d, %d) - %d\n", count, curcoord.second+j, curcoord.first+i, land[curcoord.first+i][curcoord.second+j] ? 1: 0);
                                q.push({curcoord.first+i, curcoord.second+j});
                            }
                        }
                    }
                }
            }
        }
        
        printf("%d\n", count);
        
        scanf("%d %d", &c, &r);
    }
    
    return 0;
}
