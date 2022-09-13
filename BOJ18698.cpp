#include <iostream>
#include <string>

// Solving BOJ 18698

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        int j = 0;
        for (; j < input.length(); j++) {
            if (input[j] == 'D') break;
        }
        std::cout << j << '\n';
    }

    return 0;
}
