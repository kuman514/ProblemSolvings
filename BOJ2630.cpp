#include <iostream>
#include <vector>
#include <queue>

// solving BOJ 2630

int board[128][128];

int blue = 0;
int white = 0;

void CountPapercuts(int r, int c, int length)
{
    int color = board[r][c];
    
    bool complete = true;
    
    for(int i = 0; i < length && complete; i++)
    {
        for(int j = 0; j < length && complete; j++)
        {
            if(board[r + i][c + j] != color)
            {
                complete = false;
                break;
            }
        }
    }
    
    if(complete)
    {
        if(color == 1)
        {
            blue++;
        }
        else if(color == 0)
        {
            white++;
        }
    }
    else
    {
        CountPapercuts(r, c, length / 2);
        CountPapercuts(r, c + length / 2, length / 2);
        CountPapercuts(r + length / 2, c, length / 2);
        CountPapercuts(r + length / 2, c + length / 2, length / 2);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> board[i][j];
        }
    }
    
    CountPapercuts(0, 0, n);
    std::cout << white << '\n' << blue << '\n';
    
    return 0;
}
