#include <iostream>
#include <vector>

// Solving BOJ 3009

int main(void) {
    std::vector<int> x(1001, 0);
    std::vector<int> y(1001, 0);
    
    for (int i = 0; i < 3; i++) {
        int inputX, inputY;
        std::cin >> inputX >> inputY;
        x[inputX]++;
        y[inputY]++;
    }
    
    int finalX = 0;
    for (int i = 1; i <= 1000; i++) {
        if (x[i] == 1) {
            finalX = i;
            break;
        }
    }
    
    int finalY = 0;
    for (int i = 1; i <= 1000; i++) {
        if (y[i] == 1) {
            finalY = i;
            break;
        }
    }
    
    std::cout << finalX << ' ' << finalY << '\n';

    return 0;
}
