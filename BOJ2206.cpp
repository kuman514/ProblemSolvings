#include <iostream>
#include <cstdio>
#include <queue>

// Solving BOJ 2206

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct info 
{
    int row;
    int col;
    int crush;
    int count;
    info(int Y, int X, int C, int CNT) : row(Y), col(X), crush(C), count(CNT) {}
};

char check[1001][1001][2];

int main(void)
{
    int row, col;
    scanf("%d %d", &row, &col);
    
    char road[row][col + 1];
    for(int i = 0; i < row; i++)
        scanf("%s", road[i]);
    
    std::queue<info> rque;
    info cur = info(0, 0, 0, 1);
    
    bool done = false;
    rque.push(cur);
    
    while(!rque.empty())
    {
        cur = rque.front();
        rque.pop();
        
        // check in
        if(check[cur.row][cur.col][cur.crush] == 0)
        {
            check[cur.row][cur.col][cur.crush] = 1;
        }
        else
        {
            continue;
        }
        
        // finished?
        if(cur.row == row - 1 && cur.col == col - 1)
        {
            printf("%d\n", cur.count);
            done = true;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nextR = cur.row + direction[i][0];
            int nextC = cur.col + direction[i][1];
            
            if(i < 2)
            {
                if(0 <= nextR && nextR < row && check[nextR][nextC][cur.crush] == 0)
                {
                    if(road[nextR][nextC] == '0')
                    {
                        rque.push(info(nextR, nextC, cur.crush, cur.count + 1));
                    }
                    else if(road[nextR][nextC] == '1' && cur.crush == 0)
                    {
                        rque.push(info(nextR, nextC, cur.crush + 1, cur.count + 1));
                    }
                }
            }
            else
            {
                if(0 <= nextC && nextC < col && check[nextR][nextC][cur.crush] == 0)
                {
                    if(road[nextR][nextC] == '0')
                    {
                        rque.push(info(nextR, nextC, cur.crush, cur.count + 1));
                    }
                    else if(road[nextR][nextC] == '1' && cur.crush == 0)
                    {
                        rque.push(info(nextR, nextC, cur.crush + 1, cur.count + 1));
                    }
                }
            }
        }
    }
    
    if(!done) printf("-1\n");
    
    return 0;
}
