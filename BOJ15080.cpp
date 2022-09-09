#include <iostream>

// Solving BOJ 15080

int main(void) {
    int hs, ms, ss;
    int he, me, se;
    char dummy;
    
    std::cin >> hs >> dummy >> ms >> dummy >> ss;
    std::cin >> he >> dummy >> me >> dummy >> se;
    
    int secondS = 3600 * hs + 60 * ms + ss;
    int secondE = 3600 * he + 60 * me + se;
    
    if (secondE < secondS) {
        secondE += 3600 * 24;
    }
    
    std::cout << (secondE - secondS) << '\n';

    return 0;
}
