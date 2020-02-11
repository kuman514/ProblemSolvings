#include <iostream>
#include <cstdio>

// implementing 2048 methods
// for BOJ 12100

int biggest = 0;

class puzzle2048
{
private:
    int board[20][20];
    int span;

public:
    puzzle2048(const int size) : span(size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                scanf("%d", &board[i][j]);
            }
        }
    }

    void moveUp(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all up
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[bringSpace + j][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[j + k][i] = board[j + k + bringSpace][i];
                        }

                        while (j + k < span)
                        {
                            board[j + k][i] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = 1; j < span; j++)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[j][i] != 0 && board[j][i] == board[j - 1][i])
                {
                    board[j - 1][i] *= 2;
                    board[j][i] = 0;
                }
            }

            // finish: push all up again
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[bringSpace + j][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[j + k][i] = board[j + k + bringSpace][i];
                        }

                        while (j + k < span)
                        {
                            board[j + k][i] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveDown(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all down
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[j - bringSpace][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[j - k][i] = board[j - k - bringSpace][i];
                        }

                        while (j - k >= 0)
                        {
                            board[j - k][i] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = span - 2; j >= 0; j--)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[j][i] != 0 && board[j][i] == board[j + 1][i])
                {
                    board[j + 1][i] *= 2;
                    board[j][i] = 0;
                }
            }

            // finish: push all down again
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[j][i] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[j - bringSpace][i] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[j - k][i] = board[j - k - bringSpace][i];
                        }

                        while (j - k >= 0)
                        {
                            board[j - k][i] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveLeft(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all left
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[i][bringSpace + j] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[i][j + k] = board[i][j + k + bringSpace];
                        }

                        while (j + k < span)
                        {
                            board[i][j + k] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = 1; j < span; j++)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[i][j] != 0 && board[i][j] == board[i][j - 1])
                {
                    board[i][j - 1] *= 2;
                    board[i][j] = 0;
                }
            }

            // finish: push all left again
            for (int j = 0; j < span - 1; j++)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (bringSpace + j < span)
                    {
                        if (board[i][bringSpace + j] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; k + j + bringSpace < span; k++)
                        {
                            board[i][j + k] = board[i][j + k + bringSpace];
                        }

                        while (j + k < span)
                        {
                            board[i][j + k] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    void moveRight(void)
    {
        for (int i = 0; i < span; i++)
        {
            // push all right
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[i][j - bringSpace] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[i][j - k] = board[i][j - k - bringSpace];
                        }

                        while (j - k >= 0)
                        {
                            board[i][j - k] = 0;
                            k++;
                        }
                    }
                }
            }

            // check collision between two same-value digits
            for (int j = span - 2; j >= 0; j--)
            {
                // if this position is not empty and equals to the previous, merge
                if (board[i][j] != 0 && board[i][j] == board[i][j + 1])
                {
                    board[i][j + 1] *= 2;
                    board[i][j] = 0;
                }
            }

            // finish: push all right again
            for (int j = span - 1; j >= 1; j--)
            {
                // if empty in current position, bring the next rest to it
                if (board[i][j] == 0)
                {
                    int bringSpace = 0;
                    bool allClear = true;

                    // find a space that is not 0
                    while (j - bringSpace >= 0)
                    {
                        if (board[i][j - bringSpace] != 0)
                        {
                            allClear = false;
                            break;
                        }

                        bringSpace++;
                    }

                    // if you find it, bring the next them here
                    if (!allClear)
                    {
                        int k;
                        for (k = 0; j - k - bringSpace >= 0; k++)
                        {
                            board[i][j - k] = board[i][j - k - bringSpace];
                        }

                        while (j - k >= 0)
                        {
                            board[i][j - k] = 0;
                            k++;
                        }
                    }
                }
            }
        }
    }

    int maximumNum(void)
    {
        int biggest = 0;

        for (int i = 0; i < span; i++)
        {
            for (int j = 0; j < span; j++)
            {
                if (biggest < board[i][j])
                {
                    biggest = board[i][j];
                }
            }
        }

        return biggest;
    }

    void printBoard(void)
    {
        for (int i = 0; i < span; i++)
        {
            for (int j = 0; j < span; j++)
            {
                printf("%4d ", board[i][j]);
            }

            printf("\n");
        }
    }
};

void moving(const puzzle2048& boardCopier, const int depth, const int direction)
{
    puzzle2048 copiedBoard = boardCopier;

    // copiedBoard: copied 2048 board for Backtracking
    // depth: Backtracking level (1 to 5)
    // direction: 0 - up, 1 - down, 2 - left, 3 - right

    // move the board
    switch (direction)
    {
    case 0:
        copiedBoard.moveUp();
        break;

    case 1:
        copiedBoard.moveDown();
        break;

    case 2:
        copiedBoard.moveLeft();
        break;

    case 3:
        copiedBoard.moveRight();
        break;
    }

    // check the biggest number
    const int tmp = copiedBoard.maximumNum();
    if (biggest < tmp)
    {
        biggest = tmp;
    }

    // check the depth level
    if (depth >= 5)
    {
        return;
    }

    // next depth level
    for (int i = 0; i < 4; i++)
    {
        moving(copiedBoard, depth + 1, i);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    puzzle2048 p(n);

    const int tmp = p.maximumNum();
    if (biggest < tmp)
    {
        biggest = tmp;
    }

    for (int i = 0; i < 4; i++)
    {
        moving(p, 1, i);
    }

    printf("%d\n", biggest);

    return 0;
}