#include <iostream>
#include <cstdio>
#include <vector>

// solving BOJ 3190

class snakeGameDummy
{
    private:
    // board information
    int size;
    char board[100][101];
    
    // snake information
    int direction;                          // clockwise (0 - right, 1 - down, 2 - left, 3 - up)
    std::vector< std::pair< int, int > > snakeBody;
    
    public:
    snakeGameDummy(const int span) : size(span), direction(0)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                board[i][j] = '.';
            }
            
            board[i][size] = '\0';
        }
        
        int apples;
        scanf("%d", &apples);
        
        int r, c;
        for(int i = 0; i < apples; i++)
        {
            scanf("%d %d", &r, &c);
            board[r - 1][c - 1] = 'A';
            //board[r][c] = 'A';
        }
        
        board[0][0] = '#';
        snakeBody.push_back(std::pair< int, int >(0, 0));
    }
    
    // moving forward
    // 'A' = an apple, '#' = snake body, '.' = space
    
    bool forward(void)
    {
        // returns true if game over
        
        const int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // check the collision first
        // if crushed wall or its own body, game over
        const std::pair< int, int > tmpforward = std::pair< int, int >(snakeBody[0].first + movement[direction][0], snakeBody[0].second + movement[direction][1]);
        
        if(tmpforward.first < 0 || tmpforward.first >= size)
        {
            return true;
        }
        
        if(tmpforward.second < 0 || tmpforward.second >= size)
        {
            return true;
        }
        
        if(board[tmpforward.first][tmpforward.second] == '#')
        {
            return true;
        }
        
        // stretch snake head
        snakeBody.insert(snakeBody.begin(), tmpforward);
        
        // if the snake ate an apple, tail just stays
        if(board[snakeBody[0].first][snakeBody[0].second] == 'A')
        {
            board[snakeBody[0].first][snakeBody[0].second] = '#';
        }
        
        // if there was no apple, tail follows head
        if(board[snakeBody[0].first][snakeBody[0].second] == '.')
        {
            board[snakeBody[0].first][snakeBody[0].second] = '#';
            
            const std::pair< int, int > tail = *(snakeBody.end() - 1);
            board[tail.first][tail.second] = '.';
            
            snakeBody.erase(snakeBody.end() - 1);
        }
        
        return false;
    }
    
    void turn(const char dir)
    {
        if(dir == 'D') direction++;
        else if(dir == 'L') direction--;
        
        if(direction < 0) direction = 3;
        
        direction %= 4;
    }
    
    void printBoard(void)
    {
        // print the board
        // for visualization or test print
        
        printf("direction ");
        switch(direction)
        {
            case 0:
            printf("right\n");
            break;
            
            case 1:
            printf("down\n");
            break;
            
            case 2:
            printf("left\n");
            break;
            
            case 3:
            printf("up\n");
            break;
        }
        
        for(int i = 0; i < size; i++)
        {
            printf("%s\n", board[i]);
        }
    }
};

int main(void)
{
    int span;
    scanf("%d", &span);
    
    snakeGameDummy dummy(span);
    
    int n;
    scanf("%d", &n);
    
    std::pair< int, char > command[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d %c", &command[i].first, &command[i].second);
    }
    
    int timeline = 1, commandPointer = 0;
    while(true)
    {
        /*
        // test print visualization
        printf("Timeline %d\n", timeline);
        dummy.printBoard();
        printf("\n");
        */
        
        bool isFail = dummy.forward();
        if(isFail) break;
        
        if(timeline == command[commandPointer].first)
        {
            dummy.turn(command[commandPointer].second);
            commandPointer++;
        }
        
        timeline++;
    }
    
    printf("%d\n", timeline);
    
    return 0;
}