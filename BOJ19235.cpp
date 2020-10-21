#include <iostream>

// Solving BOJ 19235

// Blocks, score
int green[6][4], blue[4][6];
int score;

// Green Functions
void GreenSetBlock(const int blockType, const int x);
int GreenInspectRow();
int GreenInspect01();
void GreenGravity();
void GreenMove(const int n);

// Blue Functions
void BlueSetBlock(const int blockType, const int y);
int BlueInspectColumn();
int BlueInspect01();
void BlueGravity();
void BlueMove(const int n);

// Final Function
int TotalBlocksLeft();

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int commands;
    std::cin >> commands;
    
    for(int i = 0; i < commands; i++)
    {
        int t, x, y;
        std::cin >> t >> x >> y;
        
        // Green Process
        GreenSetBlock(t, x);
        int greenrow = GreenInspectRow();
        while(greenrow > 0)
        {
            score += greenrow;
            
            // Gravity
            GreenGravity();
            
            // Inspect again
            greenrow = GreenInspectRow();
        }
        GreenMove(GreenInspect01());
        
        // Blue Process
        BlueSetBlock(t, y);
        int bluecolumn = BlueInspectColumn();
        while(bluecolumn > 0)
        {
            score += bluecolumn;
            
            // Gravity
            BlueGravity();
            
            // Inspect again
            bluecolumn = BlueInspectColumn();
        }
        BlueMove(BlueInspect01());
        
        /*
        // Debug Print
        std::cout << "Command " << (i + 1) << ": ";
        switch(t)
        {
            case 1:
                std::cout << "1x1, ";
                break;
            case 2:
                std::cout << "1x2, ";
                break;
            case 3:
                std::cout << "2x1, ";
                break;
        }
        std::cout << x << ", " << y << '\n';
        
        for(int i_ = 0; i_ < 4; i_++)
        {
            std::cout << "R R R R ";
            for(int j = 0; j < 6; j++)
            {
                std::cout << blue[i_][j] << ' ';
            }
            std::cout << '\n';
        }
        
        for(int i_ = 0; i_ < 6; i_++)
        {
            for(int j = 0; j < 4; j++)
            {
                std::cout << green[i_][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        */
    }
    
    std::cout << score << '\n' << TotalBlocksLeft() << '\n';

    return 0;
}

// Green Functions
void GreenSetBlock(const int blockType, const int x)
{
    int i;
    switch(blockType)
    {
        case 1:
            for(i = 0; i < 5; i++)
            {
                if(green[i + 1][x] != 0) break;
            }
            green[i][x] = 1;
            break;
        case 2:
            for(i = 1; i < 5; i++)
            {
                if(green[i + 1][x] != 0) break;
            }
            green[i - 1][x] = 1;
            green[i][x] = 1;
            break;
        case 3:
            for(i = 0; i < 5; i++)
            {
                if(green[i + 1][x] != 0 || green[i + 1][x + 1] != 0) break;
            }
            green[i][x] = 2;
            green[i][x + 1] = 2;
            break;
    }
}

int GreenInspectRow()
{
    int lines = 0;
    
    for(int i = 5; i >= 0; i--)
    {
        bool full = true;
        
        for(int j = 0; j < 4; j++)
        {
            if(green[i][j] == 0)
            {
                full = false;
                break;
            }
        }
        
        if(full)
        {
            lines++;
            
            // Erase
            for(int j = 0; j < 4; j++)
            {
                green[i][j] = 0;
            }
        }
    }
    
    return lines;
}

int GreenInspect01()
{
    int lines = 0;
    
    for(int i = 1; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            if(green[i][j] != 0)
            {
                lines++;
                break;
            }
        }
    }
    
    return lines;
}

void GreenGravity()
{
    for(int i = 5; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            switch(green[i][j])
            {
                // 1x1 blocks & 2x1 blocks
                case 1:
                    green[i][j] = 0;
                    int k;
                    
                    for(k = i; k < 5; k++)
                    {
                        if(green[k + 1][j] != 0) break;
                    }
                    
                    green[k][j] = 1;
                    break;
                // 1x2 blocks
                case 2:
                    green[i][j] = 0;
                    green[i][j + 1] = 0;
                    int k_;
                    
                    for(k_ = i; k_ < 5; k_++)
                    {
                        if(green[k_ + 1][j] != 0 || green[k_ + 1][j + 1] != 0) break;
                    }
                    
                    green[k_][j] = 2;
                    green[k_][j + 1] = 2;
                    j++;
                    break;
            }
        }
    }
}

void GreenMove(const int n)
{
    if(n <= 0) return;
    
    for(int i = 5; i >= n; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            green[i][j] = green[i - n][j];
        }
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            green[i][j] = 0;
        }
    }
}


// Blue Functions
void BlueSetBlock(const int blockType, const int y)
{
    int i;
    switch(blockType)
    {
        case 1:
            for(i = 0; i < 5; i++)
            {
                if(blue[y][i + 1] != 0) break;
            }
            blue[y][i] = 1;
            break;
        case 2:
            for(i = 0; i < 5; i++)
            {
                if(blue[y][i + 1] != 0 || blue[y + 1][i + 1] != 0) break;
            }
            blue[y][i] = 2;
            blue[y + 1][i] = 2;
            break;
        case 3:
            for(i = 1; i < 5; i++)
            {
                if(blue[y][i + 1] != 0) break;
            }
            blue[y][i - 1] = 1;
            blue[y][i] = 1;
            break;
    }
}

int BlueInspectColumn()
{
    int lines = 0;
    
    for(int i = 5; i >= 0; i--)
    {
        bool full = true;
        
        for(int j = 0; j < 4; j++)
        {
            if(blue[j][i] == 0)
            {
                full = false;
                break;
            }
        }
        
        if(full)
        {
            lines++;
            
            // Erase
            for(int j = 0; j < 4; j++)
            {
                blue[j][i] = 0;
            }
        }
    }
    
    return lines;
}

int BlueInspect01()
{
    int lines = 0;
    
    for(int i = 1; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            if(blue[j][i] != 0)
            {
                lines++;
                break;
            }
        }
    }
    
    return lines;
}

void BlueGravity()
{
    for(int i = 5; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            switch(blue[j][i])
            {
                // 1x1 blocks & 2x1 blocks
                case 1:
                    blue[j][i] = 0;
                    int k;
                    
                    for(k = i; k < 5; k++)
                    {
                        if(blue[j][k + 1] != 0) break;
                    }
                    
                    blue[j][k] = 1;
                    break;
                // 1x2 blocks
                case 2:
                    blue[j][i] = 0;
                    blue[j + 1][i] = 0;
                    int k_;
                    
                    for(k_ = i; k_ < 5; k_++)
                    {
                        if(blue[j][k_ + 1] != 0 || blue[j + 1][k_ + 1] != 0) break;
                    }
                    
                    blue[j][k_] = 2;
                    blue[j + 1][k_] = 2;
                    j++;
                    break;
            }
        }
    }
}

void BlueMove(const int n)
{
    if(n <= 0) return;
    
    for(int i = 5; i >= n; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            blue[j][i] = blue[j][i - n];
        }
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            blue[j][i] = 0;
        }
    }
}


// Final Function
int TotalBlocksLeft()
{
    int result = 0;
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(green[i][j] != 0) result++;
            if(blue[j][i] != 0) result++;
        }
    }
    
    return result;
}
