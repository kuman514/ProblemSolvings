#include <iostream>
#include <cstdio>
#include <cmath>

// solving BOJ 14891

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    char gear[4][9];
    
    // pos - [0]: left (9 o'clock), [1]: top (12 o'clock), [2]: right (3 o'clock)
    int pos[4][3] = {{6, 0, 2}, {6, 0, 2}, {6, 0, 2}, {6, 0, 2}};
    
    for(int i = 0; i < 4; i++)
    {
        std::cin >> gear[i];
    }
    
    int n;
    std::cin >> n;
    std::pair< int, int > commands[n];
    
    // command - first: gear num + 1, second: 1 = clockwise, -1 = counterclockwise
    for(int i = 0; i < n; i++)
    {
        std::cin >> commands[i].first >> commands[i].second;
    }
    
    // method starts
    for(int i = 0; i < n; i++)
    {
        int gearTurns[4] = { 0, };
        
        gearTurns[commands[i].first - 1] = commands[i].second;
        
        // left gears check
        for(int j = commands[i].first - 1; j > 0; j--)
        {
            // if poles differ each other, turn
            if(gear[j][pos[j][0]] != gear[j - 1][pos[j - 1][2]])
            {
                gearTurns[j - 1] = -gearTurns[j];
            }
            else // if poles are same each other, break
            {
                break;
            }
        }
        
        // right gears check
        for(int j = commands[i].first - 1; j < 3; j++)
        {
            // if poles differ each other, turn
            if(gear[j][pos[j][2]] != gear[j + 1][pos[j + 1][0]])
            {
                gearTurns[j + 1] = -gearTurns[j];
            }
            else // if poles are same each other, break
            {
                break;
            }
        }
        
        // gears turning
        // (rotating the position number of 9, 12, 3 o'clock)
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                pos[j][k] -= gearTurns[j];
                
                if(pos[j][k] < 0)
                {
                    pos[j][k] = 7;
                }
                
                pos[j][k] %= 8;
            }
        }
    }
    
    int score = 0;
    for(int i = 0; i < 4; i++)
    {
        score += (std::pow(2, i) * (gear[i][pos[i][1]] == '1' ? 1 : 0));
    }
    
    printf("%d\n", score);
    
    return 0;
}