#include <iostream>

// Solving BOJ 20061

// Blocks, score
int green[6][4], blue[4][6];
int score;

// Green Functions
void GreenSetBlock(const int blockType, const int x);
int GreenInspectRow(void);
int GreenInspect01(void);
void GreenGravity(const int lines);
void GreenMove(const int n);

// Blue Functions
void BlueSetBlock(const int blockType, const int y);
int BlueInspectColumn(void);
int BlueInspect01(void);
void BlueGravity(const int lines);
void BlueMove(const int n);

// Final Function
int TotalBlocksLeft(void);

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int commands;
    std::cin >> commands;
    
    for (int i = 0; i < commands; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;
        
        // Green Process
        GreenSetBlock(t, x);
        int greenrow = GreenInspectRow();
        score += greenrow;
        GreenGravity(greenrow);
        GreenMove(GreenInspect01());
        
        // Blue Process
        BlueSetBlock(t, y);
        int bluecolumn = BlueInspectColumn();
        score += bluecolumn;
        BlueGravity(bluecolumn);
        BlueMove(BlueInspect01());
        
        /*
        // Debug Print
        std::cout << "Command " << (i + 1) << ": ";
        switch (t) {
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
        
        for (int i_ = 0; i_ < 4; i_++) {
            std::cout << "R R R R ";
            for (int j = 0; j < 6; j++) {
                std::cout << blue[i_][j] << ' ';
            }
            std::cout << '\n';
        }
        
        for (int i_ = 0; i_ < 6; i_++) {
            for (int j = 0; j < 4; j++) {
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
void GreenSetBlock(const int blockType, const int x) {
    int i;
    switch (blockType) {
        case 1:
            for (i = 0; i < 5; i++) {
                if (green[i + 1][x] != 0) break;
            }
            green[i][x] = 1;
            break;
        case 2:
            for (i = 1; i < 5; i++) {
                if (green[i + 1][x] != 0) break;
            }
            green[i - 1][x] = 1;
            green[i][x] = 1;
            break;
        case 3:
            for (i = 0; i < 5; i++) {
                if (green[i + 1][x] != 0 || green[i + 1][x + 1] != 0) break;
            }
            green[i][x] = 2;
            green[i][x + 1] = 2;
            break;
    }
}

int GreenInspectRow(void) {
    int lines = 0;
    
    for (int i = 5; i >= 0; i--) {
        bool full = true;
        
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == 0) {
                full = false;
                break;
            }
        }
        
        if (full) {
            lines++;
            
            // Erase
            for (int j = 0; j < 4; j++) {
                green[i][j] = 0;
            }
        }
    }
    
    return lines;
}

int GreenInspect01(void) {
    int lines = 0;
    
    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] != 0) {
                lines++;
                break;
            }
        }
    }
    
    return lines;
}

void GreenGravity(const int lines) {
    int linesRemaining = lines;
    for (int i = 5; i >= 0 && linesRemaining > 0; i--) {
        bool isLineEmpty = true;
        for (int j = 0; j < 4; j++) {
            if (green[i][j] != 0) {
                isLineEmpty = false;
                break;
            }
        }
        
        if (!isLineEmpty) continue;
        
        while (linesRemaining > 0) {
            for (int k = i - 1; k >= 0; k--) {
                for (int j = 0; j < 4; j++) {
                    green[k + 1][j] = green[k][j];
                    green[k][j] = 0;
                }
            }
            
            linesRemaining--;
        }
    }
}

void GreenMove(const int n) {
    if (n <= 0) return;
    
    for (int i = 5; i >= n; i--) {
        for (int j = 0; j < 4; j++) {
            green[i][j] = green[i - n][j];
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            green[i][j] = 0;
        }
    }
}


// Blue Functions
void BlueSetBlock (const int blockType, const int y) {
    int i;
    switch (blockType) {
        case 1:
            for (i = 0; i < 5; i++) {
                if (blue[y][i + 1] != 0) break;
            }
            blue[y][i] = 1;
            break;
        case 2:
            for (i = 0; i < 5; i++) {
                if (blue[y][i + 1] != 0 || blue[y + 1][i + 1] != 0) break;
            }
            blue[y][i] = 2;
            blue[y + 1][i] = 2;
            break;
        case 3:
            for (i = 1; i < 5; i++) {
                if (blue[y][i + 1] != 0) break;
            }
            blue[y][i - 1] = 1;
            blue[y][i] = 1;
            break;
    }
}

int BlueInspectColumn(void) {
    int lines = 0;
    
    for (int i = 5; i >= 0; i--) {
        bool full = true;
        
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] == 0) {
                full = false;
                break;
            }
        }
        
        if (full) {
            lines++;
            
            // Erase
            for (int j = 0; j < 4; j++) {
                blue[j][i] = 0;
            }
        }
    }
    
    return lines;
}

int BlueInspect01(void) {
    int lines = 0;
    
    for (int i = 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] != 0) {
                lines++;
                break;
            }
        }
    }
    
    return lines;
}

void BlueGravity(const int lines) {
    int linesRemaining = lines;
    for (int i = 5; i >= 0 && linesRemaining > 0; i--) {
        bool isLineEmpty = true;
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] != 0) {
                isLineEmpty = false;
                break;
            }
        }
        
        if (!isLineEmpty) continue;
        
        while (linesRemaining > 0) {
            for (int k = i - 1; k >= 0; k--) {
                for (int j = 0; j < 4; j++) {
                    blue[j][k + 1] = blue[j][k];
                    blue[j][k] = 0;
                }
            }
            
            linesRemaining--;
        }
    }
}

void BlueMove(const int n) {
    if (n <= 0) return;
    
    for (int i = 5; i >= n; i--) {
        for (int j = 0; j < 4; j++) {
            blue[j][i] = blue[j][i - n];
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            blue[j][i] = 0;
        }
    }
}

// Final Function
int TotalBlocksLeft(void) {
    int result = 0;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j] != 0) result++;
            if (blue[j][i] != 0) result++;
        }
    }
    
    return result;
}
