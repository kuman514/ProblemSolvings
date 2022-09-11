#include <iostream>

// Solving BOJ 15232

int main(void) {
    int r, c;
    std::cin >> r;
    std::cin >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
