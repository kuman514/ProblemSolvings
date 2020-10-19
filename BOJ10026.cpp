#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

// Solving BOJ 10026

const int direction[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int size;
    std::cin >> size;
    
    std::vector< std::vector<char> > rgbmap(size, std::vector<char>(size, 0));
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cin >> rgbmap[i][j];
        }
    }
    
    // normal
    std::vector< std::vector<bool> > visited1(size, std::vector<bool>(size, false));
    int result1 = 0;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(!visited1[i][j])
            {
                char context = rgbmap[i][j];
                result1++;
                
                std::queue< std::pair<int, int> > next;
                next.push(std::pair<int, int>(i, j));
                
                while(!next.empty())
                {
                    std::pair<int, int> cur = next.front();
                    next.pop();
                    
                    if(visited1[cur.first][cur.second])
                    {
                        continue;
                    }
                    
                    visited1[cur.first][cur.second] = true;
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int nextR = cur.first + direction[k][0];
                        int nextC = cur.second + direction[k][1];
                        
                        if(nextR < 0 || nextR >= size) continue;
                        if(nextC < 0 || nextC >= size) continue;
                        
                        if(!visited1[nextR][nextC] && rgbmap[nextR][nextC] == context)
                        {
                            next.push(std::pair<int, int>(nextR, nextC));
                        }
                    }
                }
            }
        }
    }
    std::cout << result1 << ' ';
    
    // red green anomaly - convert
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            rgbmap[i][j] = (rgbmap[i][j] == 'B') ? 'B' : 'A';
        }
    }
    
    // red green anomaly
    std::vector< std::vector<bool> > visited2(size, std::vector<bool>(size, false));
    int result2 = 0;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(!visited2[i][j])
            {
                char context = rgbmap[i][j];
                result2++;
                
                std::queue< std::pair<int, int> > next;
                next.push(std::pair<int, int>(i, j));
                
                while(!next.empty())
                {
                    std::pair<int, int> cur = next.front();
                    next.pop();
                    
                    if(visited2[cur.first][cur.second])
                    {
                        continue;
                    }
                    
                    visited2[cur.first][cur.second] = true;
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int nextR = cur.first + direction[k][0];
                        int nextC = cur.second + direction[k][1];
                        
                        if(nextR < 0 || nextR >= size) continue;
                        if(nextC < 0 || nextC >= size) continue;
                        
                        if(!visited2[nextR][nextC] && rgbmap[nextR][nextC] == context)
                        {
                            next.push(std::pair<int, int>(nextR, nextC));
                        }
                    }
                }
            }
        }
    }
    std::cout << result2 << ' ';
    
    return 0;
}
