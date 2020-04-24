#include <iostream>
#include <cstdio>
#include <sstream>

// solving BOJ 2447

char points[2187][2188];
void getPoints(const int n, const int startRow, const int startCol)
{
    const int n3 = n / 3;
    
    /*
    position divided into 3 * 3
    1 2 3
    4 5 6
    7 8 9
    */
    
    // draw a picture for each space 1 ~ 4
    for(int i = 0; i < 4; i++)
    {
        if(n == 3) points[startRow + i / 3][startCol + i % 3] = '*';
        else getPoints(n3, startRow + n3 * (i / 3), startCol + n3 * (i % 3));
    }
    
    // draw an empty space for space 5
    for(int i = 0; i < n3; i++)
    {
        for(int j = 0; j < n3; j++)
        {
            points[startRow + n3 + i][startCol + n3 + j] = ' ';
        }
    }
    
    // draw a picture for each space 6 ~ 9
    for(int i = 5; i < 9; i++)
    {
        if(n == 3) points[startRow + i / 3][startCol + i % 3] = '*';
        else getPoints(n3, startRow + n3 * (i / 3), startCol + n3 * (i % 3));
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin >> n;
    getPoints(n, 0, 0);
    
    std::stringstream ss;
    for(int i = 0; i < n; i++)
        ss << points[i] << '\n';
    
    std::cout << ss.str();
    
    return 0;
}
