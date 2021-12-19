#include <iostream>

// Solving BOJ 16199

int main(void) {
    int y1, m1, d1;
    int y2, m2, d2;
    
    std::cin >> y1 >> m1 >> d1;
    std::cin >> y2 >> m2 >> d2;
    
    int age3 = y2 - y1;
    int age2 = age3 + 1;
    
    int age1 = age3;
    if (m1 > m2) {
        age1--;
    } else if (m1 == m2 && d1 > d2) {
        age1--;
    }
    
    std::cout << age1 << '\n';
    std::cout << age2 << '\n';
    std::cout << age3 << '\n';
    
    return 0;
}
