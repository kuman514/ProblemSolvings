#include <iostream>
#include <cstdio>
#include <queue>

// solving BOJ 7576

// point coords of a tomato
struct pnt{
    int row;
    int column;
    pnt(int R, int C) : row(R), column(C) {}
};

int main(void)
{
    int N, M;
    std::queue<pnt> tomatoqueue;
    scanf("%d %d", &M, &N);
    
    int tomato[N][M];
    int remain = 0;
    // across: i%M, down: i/M // (N lines)
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j] == 1) tomatoqueue.push(pnt(i, j));
            else if(tomato[i][j] == 0) remain++;
        }
    }
    
    int days = 0;
    pnt tmppnt = pnt(0,0);
    int tmpsize;
    
    while(!tomatoqueue.empty() && remain != 0)
    {
        days++;
        
        tmpsize = tomatoqueue.size();
        for(int i = 0; i < tmpsize; i++)
        {
            tmppnt = tomatoqueue.front();
            tomatoqueue.pop();
            
            // Up
            if(tmppnt.row - 1 >= 0 && tomato[tmppnt.row - 1][tmppnt.column] == 0)
            {
                tomatoqueue.push(pnt(tmppnt.row - 1, tmppnt.column));
                tomato[tmppnt.row - 1][tmppnt.column] = 1;
                remain--;
            }
            
            // Down
            if(tmppnt.row + 1 < N && tomato[tmppnt.row + 1][tmppnt.column] == 0)
            {
                tomatoqueue.push(pnt(tmppnt.row + 1, tmppnt.column));
                tomato[tmppnt.row + 1][tmppnt.column] = 1;
                remain--;
            }
            
            // Left
            if(tmppnt.column - 1 >= 0 && tomato[tmppnt.row][tmppnt.column - 1] == 0)
            {
                tomatoqueue.push(pnt(tmppnt.row, tmppnt.column - 1));
                tomato[tmppnt.row][tmppnt.column - 1] = 1;
                remain--;
            }
            
            // Right
            if(tmppnt.column + 1 < M && tomato[tmppnt.row][tmppnt.column + 1] == 0)
            {
                tomatoqueue.push(pnt(tmppnt.row, tmppnt.column + 1));
                tomato[tmppnt.row][tmppnt.column + 1] = 1;
                remain--;
            }
        }
    }
    
    
    if(remain != 0) printf("-1\n");
    else printf("%d\n", days);
    
    return 0;
}
