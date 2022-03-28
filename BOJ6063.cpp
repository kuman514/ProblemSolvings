#include <iostream>
#include <vector>

// Solving BOJ 6063

char cube[9][12] = {
    {'.', '.', '.', 'o', 'o', 'o', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'o', 'o', 'o', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'o', 'o', 'o', '.', '.', '.', '.', '.', '.'},
    {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b', 'y', 'y', 'y'},
    {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b', 'y', 'y', 'y'},
    {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b', 'y', 'y', 'y'},
    {'.', '.', '.', 'r', 'r', 'r', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'r', 'r', 'r', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'r', 'r', 'r', '.', '.', '.', '.', '.', '.'}
};

void commonRotate(int startR, int startC, bool reverse) {
    /*
        Common+
        [0, 0] [0, 1] [0, 2]    [2, 0] [1, 0] [0, 0]
        [1, 0] [1, 1] [1, 2] -> [2, 1] [1, 1] [0, 1]
        [2, 0] [2, 1] [2, 2]    [2, 2] [1, 2] [0, 2]
        
        Common-
        [0, 0] [0, 1] [0, 2]    [0, 2] [1, 2] [2, 2]
        [1, 0] [1, 1] [1, 2] -> [0, 1] [1, 1] [2, 1]
        [2, 0] [2, 1] [2, 2]    [0, 0] [1, 0] [2, 0]
    */
    
    // tmp blocks
    char blocks[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            blocks[i][j] = cube[startR + i][startC + j];
        }
    }
    
    if (reverse) {
        // counterclockwise (-)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[startR + i][startC + j] = blocks[j][2 - i];
            }
        }
    } else {
        // clockwise (+)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[startR + i][startC + j] = blocks[2 - j][i];
            }
        }
    }
}

void frontRotate(bool reverse) {
    /*
        U-: (2, 543) <- (345, 2) <- (6, 345) <- (543, 6) ||
        U+: (2, 345) <- (345, 6) <- (6, 543) <- (543, 2) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[5][6];
        tmp[1] = cube[4][6];
        tmp[2] = cube[3][6];
        
        cube[5][6] = cube[6][3];
        cube[4][6] = cube[6][4];
        cube[3][6] = cube[6][5];
        
        cube[6][3] = cube[3][2];
        cube[6][4] = cube[4][2];
        cube[6][5] = cube[5][2];
        
        cube[3][2] = cube[2][5];
        cube[4][2] = cube[2][4];
        cube[5][2] = cube[2][3];
        
        cube[2][5] = tmp[0];
        cube[2][4] = tmp[1];
        cube[2][3] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[5][2];
        tmp[1] = cube[4][2];
        tmp[2] = cube[3][2];
        
        cube[5][2] = cube[6][5];
        cube[4][2] = cube[6][4];
        cube[3][2] = cube[6][3];
        
        cube[6][5] = cube[3][6];
        cube[6][4] = cube[4][6];
        cube[6][3] = cube[5][6];
        
        cube[3][6] = cube[2][3];
        cube[4][6] = cube[2][4];
        cube[5][6] = cube[2][5];
        
        cube[2][3] = tmp[0];
        cube[2][4] = tmp[1];
        cube[2][5] = tmp[2];
    }
}

void backRotate(bool reverse) {
    /*
        D-: (0, 345) <- (345, 8) <- (8, 543) <- (543, 0) ||
        D+: (0, 543) <- (345, 0) <- (8, 345) <- (543, 8) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[5][0];
        tmp[1] = cube[4][0];
        tmp[2] = cube[3][0];
        
        cube[5][0] = cube[8][5];
        cube[4][0] = cube[8][4];
        cube[3][0] = cube[8][3];
        
        cube[8][5] = cube[3][8];
        cube[8][4] = cube[4][8];
        cube[8][3] = cube[5][8];
        
        cube[3][8] = cube[0][3];
        cube[4][8] = cube[0][4];
        cube[5][8] = cube[0][5];
        
        cube[0][3] = tmp[0];
        cube[0][4] = tmp[1];
        cube[0][5] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[5][8];
        tmp[1] = cube[4][8];
        tmp[2] = cube[3][8];
        
        cube[5][8] = cube[8][3];
        cube[4][8] = cube[8][4];
        cube[3][8] = cube[8][5];
        
        cube[8][3] = cube[3][0];
        cube[8][4] = cube[4][0];
        cube[8][5] = cube[5][0];
        
        cube[3][0] = cube[0][5];
        cube[4][0] = cube[0][4];
        cube[5][0] = cube[0][3];
        
        cube[0][5] = tmp[0];
        cube[0][4] = tmp[1];
        cube[0][3] = tmp[2];
    }
}

void downRotate(bool reverse) {
    /*
        F-: (5, 543) <- (5, 210) <- (5, BA9) <- (5, 876) ||
        F+: (5, 345) <- (5, 678) <- (5, 9AB) <- (5, 012) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[5][8];
        tmp[1] = cube[5][7];
        tmp[2] = cube[5][6];
        
        cube[5][8] = cube[5][11];
        cube[5][7] = cube[5][10];
        cube[5][6] = cube[5][9];
        
        cube[5][11] = cube[5][2];
        cube[5][10] = cube[5][1];
        cube[5][9] = cube[5][0];
        
        cube[5][2] = cube[5][5];
        cube[5][1] = cube[5][4];
        cube[5][0] = cube[5][3];
        
        cube[5][5] = tmp[0];
        cube[5][4] = tmp[1];
        cube[5][3] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[5][0];
        tmp[1] = cube[5][1];
        tmp[2] = cube[5][2];
        
        cube[5][0] = cube[5][9];
        cube[5][1] = cube[5][10];
        cube[5][2] = cube[5][11];
        
        cube[5][9] = cube[5][6];
        cube[5][10] = cube[5][7];
        cube[5][11] = cube[5][8];
        
        cube[5][6] = cube[5][3];
        cube[5][7] = cube[5][4];
        cube[5][8] = cube[5][5];
        
        cube[5][3] = tmp[0];
        cube[5][4] = tmp[1];
        cube[5][5] = tmp[2];
    }
}

void upRotate(bool reverse) {
    /*
        B-: (3, 345) <- (3, 678) <- (3, 9AB) <- (3, 012) ||
        B+: (3, 543) <- (3, 210) <- (3, BA9) <- (3, 876) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[3][0];
        tmp[1] = cube[3][1];
        tmp[2] = cube[3][2];
        
        cube[3][0] = cube[3][9];
        cube[3][1] = cube[3][10];
        cube[3][2] = cube[3][11];
        
        cube[3][9] = cube[3][6];
        cube[3][10] = cube[3][7];
        cube[3][11] = cube[3][8];
        
        cube[3][6] = cube[3][3];
        cube[3][7] = cube[3][4];
        cube[3][8] = cube[3][5];
        
        cube[3][3] = tmp[0];
        cube[3][4] = tmp[1];
        cube[3][5] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[3][8];
        tmp[1] = cube[3][7];
        tmp[2] = cube[3][6];
        
        cube[3][8] = cube[3][11];
        cube[3][7] = cube[3][10];
        cube[3][6] = cube[3][9];
        
        cube[3][11] = cube[3][2];
        cube[3][10] = cube[3][1];
        cube[3][9] = cube[3][0];
        
        cube[3][2] = cube[3][5];
        cube[3][1] = cube[3][4];
        cube[3][0] = cube[3][3];
        
        cube[3][5] = tmp[0];
        cube[3][4] = tmp[1];
        cube[3][3] = tmp[2];
    }
}

void leftRotate(bool reverse) {
    /*
        L-: (543, 3) <- (210, 3) <- (345, B) <- (876, 3) ||
        L+: (345, 3) <- (678, 3) <- (543, B) <- (012, 3) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[8][3];
        tmp[1] = cube[7][3];
        tmp[2] = cube[6][3];
        
        cube[8][3] = cube[3][11];
        cube[7][3] = cube[4][11];
        cube[6][3] = cube[5][11];
        
        cube[3][11] = cube[2][3];
        cube[4][11] = cube[1][3];
        cube[5][11] = cube[0][3];
        
        cube[2][3] = cube[5][3];
        cube[1][3] = cube[4][3];
        cube[0][3] = cube[3][3];
        
        cube[5][3] = tmp[0];
        cube[4][3] = tmp[1];
        cube[3][3] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[0][3];
        tmp[1] = cube[1][3];
        tmp[2] = cube[2][3];
        
        cube[0][3] = cube[5][11];
        cube[1][3] = cube[4][11];
        cube[2][3] = cube[3][11];
        
        cube[5][11] = cube[6][3];
        cube[4][11] = cube[7][3];
        cube[3][11] = cube[8][3];
        
        cube[6][3] = cube[3][3];
        cube[7][3] = cube[4][3];
        cube[8][3] = cube[5][3];
        
        cube[3][3] = tmp[0];
        cube[4][3] = tmp[1];
        cube[5][3] = tmp[2];
        
    }
}

void rightRotate(bool reverse) {
    /*
        R-: (345, 5) <- (678, 5) <- (543, 9) <- (012, 5) ||
        R+: (543, 5) <- (210, 5) <- (345, 9) <- (876, 5) ||
    */
    
    char tmp[3];
    if (reverse) {
        // counterclockwise (-)
        tmp[0] = cube[0][5];
        tmp[1] = cube[1][5];
        tmp[2] = cube[2][5];
        
        cube[0][5] = cube[5][9];
        cube[1][5] = cube[4][9];
        cube[2][5] = cube[3][9];
        
        cube[5][9] = cube[6][5];
        cube[4][9] = cube[7][5];
        cube[3][9] = cube[8][5];
        
        cube[6][5] = cube[3][5];
        cube[7][5] = cube[4][5];
        cube[8][5] = cube[5][5];
        
        cube[3][5] = tmp[0];
        cube[4][5] = tmp[1];
        cube[5][5] = tmp[2];
    } else {
        // clockwise (+)
        tmp[0] = cube[8][5];
        tmp[1] = cube[7][5];
        tmp[2] = cube[6][5];
        
        cube[8][5] = cube[3][9];
        cube[7][5] = cube[4][9];
        cube[6][5] = cube[5][9];
        
        cube[3][9] = cube[2][5];
        cube[4][9] = cube[1][5];
        cube[5][9] = cube[0][5];
        
        cube[2][5] = cube[5][5];
        cube[1][5] = cube[4][5];
        cube[0][5] = cube[3][5];
        
        cube[5][5] = tmp[0];
        cube[4][5] = tmp[1];
        cube[3][5] = tmp[2];
    }
}

void testCase(int scenarioNum) {
    // Get cube information
    for (int i = 0; i < 9; i++) {
        const int start = ((3 <= i && i < 6) ? 0 : 3);
        const int end = ((3 <= i && i < 6) ? 12 : 6);
        
        for (int j = start; j < end; j++) {
            std::cin >> cube[i][j];
        }
    }
    
    // Get commands
    int commands;
    std::cin >> commands;
    for (int cur = 0; cur < commands; cur++) {
        int side;
        int direction;
        std::cin >> side >> direction;
        bool isRev = (direction == -1);
        
        switch (side) {
            case 0:
                // Left
                commonRotate(3, 0, isRev);
                leftRotate(isRev);
                break;
            case 1:
                // Front
                commonRotate(3, 3, isRev);
                frontRotate(isRev);
                break;
            case 2:
                // Right
                commonRotate(3, 6, isRev);
                rightRotate(isRev);
                break;
            case 3:
                // Back
                commonRotate(3, 9, isRev);
                backRotate(isRev);
                break;
            case 4:
                // Top
                commonRotate(0, 3, isRev);
                upRotate(isRev);
                break;
            case 5:
                // Bottom
                commonRotate(6, 3, isRev);
                downRotate(isRev);
                break;
        }
    }
    
    // Print result
    std::cout << "Scenario #" << scenarioNum << ":\n";
    for (int i = 0; i < 9; i++) {
        if (!(3 <= i && i < 6)) {
            std::cout << "      ";
        }
        
        const int start = ((3 <= i && i < 6) ? 0 : 3);
        const int end = ((3 <= i && i < 6) ? 12 : 6);
        
        for (int j = start; j < end; j++) {
            if (j == end - 1) {
                std::cout << cube[i][j] << '\n';
            } else {
                std::cout << cube[i][j] << ' ';
            }
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int testcase;
    std::cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        testCase(i + 1);
        if (i < testcase - 1) {
            std::cout << '\n';
        }
    }

    return 0;
}
