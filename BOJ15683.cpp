#include <iostream>
#include <cstdio>

// solving BOJ 15683

// 0: space, 1~5: cctv cam, 6: wall, 7: painted
const int space = 0;
const int wall = 6;
const int painted = 7;

const int direction[4][4][2] = {{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} },
                                { {1, 0}, {-1, 0}, {0, 1}, {0, -1} },
                                { {0, -1}, {0, 1}, {-1, 0}, {1, 0} },
                                { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

int minimumSpace = 1000000000;

class cctvMap
{
    private:
    // map information
    int row;
    int col;
    int cctvmap[8][8];
    
    // cctv information
    int cctvcap;
    std::pair< int, int > cctvpos[8];
    
    public:
    cctvMap(const int r, const int c) : row(r), col(c), cctvcap(0)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                // map input
                scanf("%d", &cctvmap[i][j]);
                
                // save each cctv information
                if(1 <= cctvmap[i][j] && cctvmap[i][j] <= 5)
                {
                    cctvpos[cctvcap] = std::pair< int, int >(i, j);
                    cctvcap++;
                }
            }
        }
    }
    
    // cctv individual paint methods
    void paint(const int cctvIndex, const int rotation)
    {
        int directionCapacity;
        bool cctvtype3;
        
        switch(cctvmap[cctvpos[cctvIndex].first][cctvpos[cctvIndex].second])
        {
            case 1:
            directionCapacity = 1;
            cctvtype3 = false;
            break;
            
            case 2:
            directionCapacity = 2;
            cctvtype3 = false;
            break;
            
            case 3:
            directionCapacity = 3;
            cctvtype3 = true;
            break;
            
            case 4:
            directionCapacity = 3;
            cctvtype3 = false;
            break;
            
            case 5:
            directionCapacity = 4;
            cctvtype3 = false;
            break;
        }
        
        if(cctvtype3)
        {
            for(int i = 0; i < directionCapacity; i += 2)
            {
                int rpos = cctvpos[cctvIndex].first + direction[i][rotation / 2][0];
                int cpos = cctvpos[cctvIndex].second + direction[i][rotation % 2][1];
                
                while((0 <= rpos && rpos < row) && (0 <= cpos && cpos < col))
                {
                    if(cctvmap[rpos][cpos] == wall)
                    {
                        // blocked by a wall
                        break;
                    }
                    else if(cctvmap[rpos][cpos] == space)
                    {
                        // empty space painted
                        cctvmap[rpos][cpos] = painted;
                    }
                    
                    rpos += direction[i][rotation / 2][0];
                    cpos += direction[i][rotation % 2][1];
                }
            }
        }
        else
        {
            for(int i = 0; i < directionCapacity; i++)
            {
                int rpos = cctvpos[cctvIndex].first + direction[i][rotation][0];
                int cpos = cctvpos[cctvIndex].second + direction[i][rotation][1];
                
                while((0 <= rpos && rpos < row) && (0 <= cpos && cpos < col))
                {
                    if(cctvmap[rpos][cpos] == wall)
                    {
                        // blocked by a wall
                        break;
                    }
                    else if(cctvmap[rpos][cpos] == space)
                    {
                        // empty space painted
                        cctvmap[rpos][cpos] = painted;
                    }
                    
                    rpos += direction[i][rotation][0];
                    cpos += direction[i][rotation][1];
                }
            }
        }
        
        
    }
    
    int getEmptySpaces(void)
    {
        int result = 0;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(cctvmap[i][j] == 0)
                {
                    result++;
                }
            }
        }
        
        return result;
    }
    
    int getCCTVNumbers(void)
    {
        return cctvcap;
    }
    
    int checkCCTVType(const int cctvIndex)
    {
        return cctvmap[cctvpos[cctvIndex].first][cctvpos[cctvIndex].second];
    }
    
    void printMap(void)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d ", cctvmap[i][j]);
            }
            
            printf("\n");
        }
    }
};

void paintArea(cctvMap cm, const int cctvIndex, const int direction)
{
    cm.paint(cctvIndex, direction);
    
    /*
    // test print
    printf("CCTV %d\n", cctvIndex);
    cm.printMap();
    printf("\n");
    */
    
    if(cctvIndex >= cm.getCCTVNumbers() - 1)
    {
        int currentEmptySpaces = cm.getEmptySpaces();
        if(minimumSpace > currentEmptySpaces)
        {
            minimumSpace = currentEmptySpaces;
        }
        
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        // filtering skip method by the cam type
        const int cctvType = cm.checkCCTVType(cctvIndex + 1);
        if(cctvType == 2 && i % 2 == 1)
        {
            continue;
        }
        else if(cctvType == 5 && i > 0)
        {
            break;
        }
        
        paintArea(cm, cctvIndex + 1, i);
    }
}

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    
    cctvMap cm(row, col);
    
    // if the room has no cctv?
    if(cm.getCCTVNumbers() <= 0)
    {
        printf("%d\n", cm.getEmptySpaces());
        
        return 0;
    }
    
    // cam paint method starts
    for(int i = 0; i < 4; i++)
    {
        // filtering skip method by the cam type
        const int cctvType = cm.checkCCTVType(0);
        if(cctvType == 2 && i % 2 == 1)
        {
            continue;
        }
        else if(cctvType == 5 && i > 0)
        {
            break;
        }
        
        paintArea(cm, 0, i);
    }
    
    printf("%d\n", minimumSpace);
    
    return 0;
}