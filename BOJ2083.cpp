#include <iostream>
#include <string>

// Solving BOJ 2083

int main(void) {
    std::string name;
    int age, weight;

    while (true) {
        std::cin >> name >> age >> weight;
        if (name[0] == '#' && age == 0 && weight == 0) {
            break;
        }

        std::cout << name << ' ';
        if (age > 17 || weight >= 80) {
            std::cout << "Senior";
        } else {
            std::cout << "Junior";
        }
        std::cout << '\n';
    }

    return 0;
}
