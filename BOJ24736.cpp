#include <iostream>

// Solving BOJ 24736

int main(void) {
    int t1, f1, s1, p1, c1;
    std::cin >> t1 >> f1 >> s1 >> p1 >> c1;
    int score1 = (6 * t1) + (3 * f1) + (2 * s1) + (1 * p1) + (2 * c1);
    
    int t2, f2, s2, p2, c2;
    std::cin >> t2 >> f2 >> s2 >> p2 >> c2;
    int score2 = (6 * t2) + (3 * f2) + (2 * s2) + (1 * p2) + (2 * c2);
    
    std::cout << score1 << ' ' << score2 << '\n';

    return 0;
}
