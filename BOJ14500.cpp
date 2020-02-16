#include <iostream>
#include <cstdio>

// solving BOJ 14500

struct tetromino
{
    bool enable[4][4];
    int rspan;
    int cspan;
    
    tetromino(const int r, const int c, const char* entry) : rspan(r), cspan(c)
    {
        int ptr = 0;
        for(int i = 0; i < rspan; i++)
        {
            for(int j = 0; j < cspan; j++)
            {
                enable[i][j] = (entry[ptr] == '1') ? true : ((entry[ptr] == '0') ? false : true);
                ptr++;
            }
        }
    }
};

/*
    1. I Shape: 2 Rotations
    1111    1
            1
            1
            1
    
    2. O Shape: 1 Rotation
    11
    11
    
    3. L Shape: 8 Rotations
    10  001 11  111 01  111 11  100
    10  111 01  100 01  001 10  111
    11      01      11      10
    
    4. Z Shape: 4 Rotations
    110 01  011 10
    011 11  110 11
        10      01
    
    5. T Shape: 4 Rotations
    111 01  010 10
    010 11  111 11
        01      10
*/

// pre-made tetrominos
tetromino tet[19] = { tetromino(1, 4, "1111"), tetromino(4, 1, "1111"),
                      tetromino(2, 2, "1111"),
                      tetromino(3, 2, "101011"), tetromino(2, 3, "001111"), tetromino(3, 2, "110101"), tetromino(2, 3, "111100"),
                      tetromino(3, 2, "010111"), tetromino(2, 3, "111001"), tetromino(3, 2, "111010"), tetromino(2, 3, "100111"),
                      tetromino(2, 3, "110011"), tetromino(3, 2, "011110"), tetromino(2, 3, "011110"), tetromino(3, 2, "101101"),
                      tetromino(2, 3, "111010"), tetromino(3, 2, "011101"), tetromino(2, 3, "010111"), tetromino(3, 2, "101110") };

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int row, col;
    std::cin >> row >> col;
    
    int value[row][col];
    
    // matrix input
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            std::cin >> value[i][j];
        }
    }
    
    int maxSum = 0;
    
    for(int T = 0; T < 19; T++)
    {
        for(int iSpawn = 0; iSpawn < row - tet[T].rspan + 1; iSpawn++)
        {
            for(int jSpawn = 0; jSpawn < col - tet[T].cspan + 1; jSpawn++)
            {
                // getting sum
                int sum = 0;
                
                for(int i = 0; i < tet[T].rspan; i++)
                {
                    for(int j = 0; j < tet[T].cspan; j++)
                    {
                        if(tet[T].enable[i][j])
                        {
                            sum += value[iSpawn + i][jSpawn + j];
                        }
                    }
                }
                
                // compare sum
                if(maxSum < sum)
                {
                    maxSum = sum;
                }
            }
        }
    }
    
    printf("%d\n", maxSum);
    
    return 0;
}