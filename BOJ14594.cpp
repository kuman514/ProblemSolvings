#include <iostream>
#include <vector>

// Solving BOJ 14594

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, m;
    std::cin >> n;
    std::cin >> m;
    
    // Init rooms
    std::vector<bool> wall(n - 1, true);
    int remain = n - 1;
    
    // Get walls to breach
    for (int i = 0; i < m; i++) {
        int org, dst;
        std::cin >> org >> dst;
        
        org--;
        dst--;
        
        for (int j = org; j < dst; j++) {
            if (wall[j]) {
                wall[j] = false;
                remain--;
            }
        }
    }
    
    std::cout << (remain + 1) << '\n';

    return 0;
}
