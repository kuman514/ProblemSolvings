#include <iostream>
#include <numeric>
#include <cmath>

// Solving BOJ 1393

int main(void) {
    int xs, ys, xe, ye, dx, dy;
    std::cin >> xs >> ys >> xe >> ye >> dx >> dy;
    
    int dGcd = std::gcd(std::abs(dx), std::abs(dy));
    dx /= dGcd;
    dy /= dGcd;
    
    double nearstDist = 8000000.0;
    int nearstX = xe;
    int nearstY = ye;
    
    while (-100 <= xe && xe <= 100 && -100 <= ye && ye <= 100) {
        double curDist = std::sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
        
        if (nearstDist > curDist) {
            nearstDist = curDist;
            nearstX = xe;
            nearstY = ye;
        }
    
        xe += dx;
        ye += dy;
    }
    
    std::cout << nearstX << ' ' << nearstY << '\n';

    return 0;
}
