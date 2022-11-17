#include <iostream>
#include <vector>

// Solving BOJ 14939

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get original lights
    std::vector< std::vector<bool> > light(10, std::vector<bool>(10, false));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char input;
            std::cin >> input;
            
            switch (input) {
                case '#':
                    light[i][j] = false;
                    break;
                case 'O':
                    light[i][j] = true;
                    break;
            }
        }
    }
    
    /*
        Rules
        1. Switch order dosen't matter
        2. Start from the very first line (2 ** 10 == 1024)
        3. The rest depend on ones right above
    */
    
    std::vector<int> bitMaskValues(10, 1);
    for (int i = 0; i < 10; i++) {
        bitMaskValues[i] <<= i;
    }
    
    const int directions[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int minimumSwitches = -1;
    for (int cur = 0; cur < 1024; cur++) {
        int curSwitches = 0;
        
        // Copy original lights
        std::vector< std::vector<bool> > curLight(10, std::vector<bool>(10, false));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                curLight[i][j] = light[i][j];
            }
        }
        
        // Hit switches on the very first line
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 10; j++) {
                if (cur & bitMaskValues[j]) {
                    curSwitches++;
                    for (int k = 0; k < 5; k++) {
                        const int curR = i + directions[k][0];
                        const int curC = j + directions[k][1];
                        
                        // Out of range?
                        if (curR < 0 || curR >= 10 || curC < 0 || curC >= 10) {
                            continue;
                        }
                        
                        curLight[curR][curC] = !curLight[curR][curC];
                    }
                }
            }
        }
        
        // Hit the rest switches
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (curLight[i - 1][j]) {
                    curSwitches++;
                    for (int k = 0; k < 5; k++) {
                        const int curR = i + directions[k][0];
                        const int curC = j + directions[k][1];
                        
                        // Out of range?
                        if (curR < 0 || curR >= 10 || curC < 0 || curC >= 10) {
                            continue;
                        }
                        
                        curLight[curR][curC] = !curLight[curR][curC];
                    }
                }
            }
        }
        
        // Check all switches are down
        bool allDown = true;
        for (int i = 0; i < 10 && allDown; i++) {
            for (int j = 0; j < 10 && allDown; j++) {
                if (curLight[i][j]) {
                    allDown = false;
                }
            }
        }
        
        if (allDown) {
            if (minimumSwitches < 0 || minimumSwitches > curSwitches) {
                minimumSwitches = curSwitches;
            }
        }
    }
    
    std::cout << minimumSwitches << '\n';
    
    return 0;
}
