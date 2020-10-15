#include <iostream>
#include <cstdio>

// solving BOJ 1987

const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char map[20][21];
int r, c;
int longest = 0;

bool visited[26] = {0,};

void track(const int y, const int x, const int length)
{
    visited[map[y][x] - 'A'] = true;
    
    if (longest < length)
    {
        longest = length;
    }
    
    /*
    std::cout << "length: " << length << ", ";
    std::cout << "x: " << x << ", ";
    std::cout << "y: " << y << "\n";
    */
    
    for(int i = 0; i < 4; i++)
    {
        int nextY = y + direction[i][0];
        int nextX = x + direction[i][1];
        
        /*
        std::cout << "next x: " << nextX << ", ";
        std::cout << "next y: " << nextY << ", ";
        std::cout << "letter: " << map[nextY][nextX] << '\n';
        */
        
        // If out of range, pass.
        if(nextY < 0 || nextY >= r) continue;
        if(nextX < 0 || nextX >= c) continue;
        
        // If redundant(already visited) letter, pass.
        if(visited[map[nextY][nextX] - 'A']) continue;
        
        track(nextY, nextX, length + 1);
    }
    
    visited[map[y][x] - 'A'] = false;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
    }
    
    /*
    for(int i = 0; i < r; i++)
    {
        std::cout << map[i] << '\n';
    }
    */
    
    track(0, 0, 1);
    
    std::cout << longest << '\n';
    
    return 0;
}
