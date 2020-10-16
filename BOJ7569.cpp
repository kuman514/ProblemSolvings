#include <iostream>
#include <cstdio>
#include <queue>

// Optimizing solution of BOJ 7569

const int direction[6][3] = {{0, -1, 0}, {0, 1, 0},
                             {0, 0, -1}, {0, 0, 1},
                             {-1, 0, 0}, {1, 0, 0}};

struct pnt
{
    int height;
    int row;
    int column;
    pnt(int H, int R, int C) : height(H), row(R), column(C) {}
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M, H;
    std::queue<pnt> tomatoqueue;
    std::cin >> M >> N >> H;
    
    int tomato[H][N][M];
    int remain = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                std::cin >> tomato[i][j][k];
                
                if(tomato[i][j][k] == 1) tomatoqueue.push(pnt(i,j,k));
                else if(tomato[i][j][k] == 0) remain++;
            }
        }
    }
    
    int days = 0;
    pnt tmppnt = pnt(0, 0, 0);
    int tmpsize;
    
    // check this to be done by counting the number of remaining tomatoes
    while(!tomatoqueue.empty() && remain != 0)
    {
        days++;
        
        tmpsize = tomatoqueue.size();
        for(int i = 0; i < tmpsize; i++)
        {
            tmppnt = tomatoqueue.front();
            tomatoqueue.pop();
            
            for(int j = 0; j < 6; j++)
            {
                int nextH = tmppnt.height + direction[j][0];
                int nextR = tmppnt.row + direction[j][1];
                int nextC = tmppnt.column + direction[j][2];
                
                if(nextH < 0 || nextH >= H) continue;
                if(nextR < 0 || nextR >= N) continue;
                if(nextC < 0 || nextC >= M) continue;
                
                if(tomato[nextH][nextR][nextC] == 0)
                {
                    tomatoqueue.push(pnt(nextH, nextR, nextC));
                    tomato[nextH][nextR][nextC] = 1;
                    remain--;
                }
            }
        }
    }
    
    if(remain != 0) std::cout << "-1\n";
    else std::cout << days << '\n';
    
    return 0;
}
