#include <iostream>
#include <string>

// Solving BOJ 13985

int main(void) {
    std::string input;
    std::getline(std::cin, input);
    
    int a = static_cast<int>(input[0] - '0');
    int b = static_cast<int>(input[4] - '0');
    int c = static_cast<int>(input[8] - '0');
    
    std::cout << ((a + b == c) ? "YES\n" : "NO\n");

    return 0;
}
