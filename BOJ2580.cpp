#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

// Solving BOJ 2580

// first: row, second: column
std::vector< std::pair<int, int> > hole;

int board[9][9];

void Check()
{
    bool isDuplicate[10] = {false,};
    
    // Check rows
    for(int i = 0; i < 9; i++)
    {
        memset(isDuplicate, false, sizeof(isDuplicate));
        
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != 0 && isDuplicate[board[i][j]])
            {
                return;
            }
            else
            {
                isDuplicate[board[i][j]] = true;
            }
        }
    }
    
    // Check columns
    for(int i = 0; i < 9; i++)
    {
        memset(isDuplicate, false, sizeof(isDuplicate));
        
        for(int j = 0; j < 9; j++)
        {
            if(board[j][i] != 0 && isDuplicate[board[j][i]])
            {
                return;
            }
            else
            {
                isDuplicate[board[j][i]] = true;
            }
        }
    }
    
    // Check squares
    for(int i = 0; i < 9; i++)
    {
        memset(isDuplicate, false, sizeof(isDuplicate));
        
        int sqrow = (i / 3) * 3;
        int sqcol = (i % 3) * 3;
        
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(board[sqrow + j][sqcol + k] != 0 && isDuplicate[board[sqrow + j][sqcol + k]])
                {
                    return;
                }
                else
                {
                    isDuplicate[board[sqrow + j][sqcol + k]] = true;
                }
            }
        }
    }
    
    // If complete, print and exit
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            std::cout << board[i][j] << ' ';
        }
        
        std::cout << '\n';
    }
    
    exit(0);
}

void GetBoard(int cur)
{
    int row = hole[cur].first;
    int col = hole[cur].second;
    
    int sqrow = (hole[cur].first / 3) * 3;
    int sqcol = (hole[cur].second / 3) * 3;
    
    // Check possible answers for every holes
    bool isDuplicate[10] = {false,};
    
    // check row
    for(int j = 0; j < 9; j++)
    {
        isDuplicate[board[row][j]] = true;
    }
    
    // check column
    for(int j = 0; j < 9; j++)
    {
        isDuplicate[board[j][col]] = true;
    }
    
    // check square
    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 3; k++)
        {
            isDuplicate[board[sqrow + j][sqcol + k]] = true;
        }
    }
    
    // Go to possible answers
    for(int j = 1; j <= 9; j++)
    {
        if(!isDuplicate[j])
        {
            // Fill answer
            board[hole[cur].first][hole[cur].second] = j;
            
            // Next point
            if(cur >= hole.size() - 1)
            {
                Check();
            }
            else
            {
                GetBoard(cur + 1);
            }
        }
    }
    
    // If this point is not promising, return to 0
    board[hole[cur].first][hole[cur].second] = 0;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            std::cin >> board[i][j];
            
            // Hole?
            if(board[i][j] == 0)
            {
                hole.push_back({i, j});
            }
        }
    }
    
    GetBoard(0);
    
    return 0;
}
