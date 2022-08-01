#include <iostream>
#include <vector>
#include <string>

// Solving BOJ 21655

int main(void) {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> map1;
    for (int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        map1.push_back(input);
    }
    
    std::vector<std::string> map2;
    for (int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        map2.push_back(input);
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map1[i][j] == map2[i][j]) {
                result++;
            }
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
