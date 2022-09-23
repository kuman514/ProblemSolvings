#include <iostream>
#include <string>

// Solving BOJ 11121

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string input1, input2;
        std::cin >> input1 >> input2;
        
        if (input1.length() != input2.length()) {
            std::cout << "ERROR\n";
            continue;
        }
        
        int wrong = 0;
        for (int j = 0; j < input1.length(); j++) {
            if (input1[j] != input2[j]) {
                wrong++;
            }
        }
        
        int invertedWrong = 0;
        for (int j = 0; j < input1.length(); j++) {
            if (input1[j] == input2[j]) {
                invertedWrong++;
            }
        }
        
        if (wrong > 0 && invertedWrong > 0) {
            std::cout << "ERROR";
        } else {
            std::cout << "OK";
        }
        
        std::cout << '\n';
    }

    return 0;
}
