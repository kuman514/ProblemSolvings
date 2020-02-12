#include <iostream>
#include <cstdio>

// Solving BOJ 13460

int minimumTilts = 11;

class mazeBoard
{
private:
    char map[10][11];
    int rspan;
    int cspan;

    // Balls' Position - first: row, second: column
    std::pair< int, int > redBallPos;
    std::pair< int, int > blueBallPos;

    bool redBallOut;

public:
    mazeBoard(const int RSP, const int CSP) : rspan(RSP), cspan(CSP), redBallOut(false)
    {
        for (int i = 0; i < RSP; i++)
        {
            scanf("%s", map[i]);

            for (int j = 0; map[i][j] != '\0'; j++)
            {
                if (map[i][j] == 'R')
                {
                    redBallPos.first = i;
                    redBallPos.second = j;
                }
                else if (map[i][j] == 'B')
                {
                    blueBallPos.first = i;
                    blueBallPos.second = j;
                }
            }
        }
    }

    // tilting - returning true means fail (blue ball at the hole)

    bool tilt(const int d)
    {
        const int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

        // Moving the Red Ball
        while (map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] == '.' && !redBallOut)
        {
            // move one block forward
            map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] = 'R';
            map[redBallPos.first][redBallPos.second] = '.';
            redBallPos.first += dir[d][0];
            redBallPos.second += dir[d][1];
        }

        // if it reaches the hole, get the red ball out
        if (map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] == 'O')
        {
            map[redBallPos.first][redBallPos.second] = '.';
            redBallOut = true;
        }

        // Moving the Blue Ball
        while (map[blueBallPos.first + dir[d][0]][blueBallPos.second + dir[d][1]] == '.')
        {
            // move one block forward
            map[blueBallPos.first + dir[d][0]][blueBallPos.second + dir[d][1]] = 'B';
            map[blueBallPos.first][blueBallPos.second] = '.';
            blueBallPos.first += dir[d][0];
            blueBallPos.second += dir[d][1];
        }

        // if the blue ball gets to the hole, it ends to fail
        if (map[blueBallPos.first + dir[d][0]][blueBallPos.second + dir[d][1]] == 'O')
        {
            return true;
        }

        // Trying Moving the Red Ball again
        // because the Blue Ball might block the Red Ball
        while (map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] == '.' && !redBallOut)
        {
            // move one block forward
            map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] = 'R';
            map[redBallPos.first][redBallPos.second] = '.';
            redBallPos.first += dir[d][0];
            redBallPos.second += dir[d][1];
        }

        // if it reaches the hole, get the red ball out
        if (map[redBallPos.first + dir[d][0]][redBallPos.second + dir[d][1]] == 'O')
        {
            map[redBallPos.first][redBallPos.second] = '.';
            redBallOut = true;
        }

        return false;
    }

    bool isRedBallOut(void)
    {
        return redBallOut;
    }

    void printMap(void)
    {
        for (int i = 0; i < rspan; i++)
        {
            printf("%s\n", map[i]);
        }
    }
};

void tiltMaze(mazeBoard copiedBoard, const int depth, const int direction)
{
    // copiedBoard: a copied Board from original or previous level
    // depth: number of tilts (up to 10 tilts)
    // direction: tilt direction (0 - up, 1 - down, 2 - left, 3 - right)

    // tilt
    bool isFail = copiedBoard.tilt(direction);

    /*
    // test print
    printf("tilt %d\n", depth);
    copiedBoard.printMap();
    printf("\n");
    */

    // check the fail
    if (isFail)
    {
        return;
    }

    // check the red ball out of board
    if (copiedBoard.isRedBallOut())
    {
        if (minimumTilts > depth)
        {
            minimumTilts = depth;
        }

        return;
    }

    // depth level check
    if (depth >= 10)
    {
        return;
    }

    // next level
    for (int i = 0; i < 4; i++)
    {
        tiltMaze(copiedBoard, depth + 1, i);
    }
}

int main(void)
{
    int r, c;
    scanf("%d %d", &r, &c);

    mazeBoard mzb(r, c);

    // tilt start
    for (int i = 0; i < 4; i++)
    {
        tiltMaze(mzb, 1, i);
    }

    printf("%d\n", (minimumTilts == 11) ? -1 : minimumTilts);

    return 0;
}