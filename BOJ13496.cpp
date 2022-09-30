#include <iostream>

// Solving BOJ 13496

int main(void) {
    int k;
    std::cin >> k;
    
    for (int i = 0; i < k; i++) {
        int n, s, d;
        std::cin >> n >> s >> d;
        
        int total = 0;
        int req = s * d;
        for (int j = 0; j < n; j++) {
            int r, v;
            std::cin >> r >> v;
            
            if (r <= req) {
                total += v;
            }
        }
        
        std::cout << "Data Set " << (i + 1) << ":\n";
        std::cout << total << '\n';
        
        if (i < k - 1) {
            std::cout << '\n';
        }
    }

    return 0;
}
