#include <iostream>

// Solving BOJ 4299

int main(void) {
    int s, t;
    std::cin >> s >> t;
    
    /*
        a + b = s
        a - b = t
        
        2a = s + t
        2b = s - t
    */
    
    if ((s + t) % 2 == 1 || (s - t) % 2 == 1 || (s + t) < 0 || (s - t) < 0) {
        std::cout << (-1) << '\n';
    } else {
        std::cout << ((s + t) / 2) << ' ' << ((s - t) / 2) << '\n';
    }
    
    return 0;
}
