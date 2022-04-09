#include <iostream>
#include <vector>

// Solving BOJ 9655

int main(void) {
    int n;
    std::cin >> n;
    
    // Memoization for their doing best
    // [0]: 1 -> 1, [1]: 1 -> 3, [2]: 3 -> 1, [3]: 3 -> 3
    std::vector< std::vector<int> > maximumStones;
    maximumStones.push_back({1, 3, 1, 3});
    bool found = false;
    while (!found) {
        const int recent = maximumStones.size() - 1;
        // If something == n, it's found
        for (int i = 0; i < 4; i++) {
            if (maximumStones[recent][i] == n) {
                found = true;
                break;
            }
        }
        
        if (found) {
            break;
        }
        
        int curStone[4] = { 0, };
        curStone[0] = std::max(maximumStones[recent][0], maximumStones[recent][2]) + 1;
        curStone[1] = std::max(maximumStones[recent][0], maximumStones[recent][2]) + 3;
        curStone[2] = std::max(maximumStones[recent][1], maximumStones[recent][3]) + 1;
        curStone[3] = std::max(maximumStones[recent][1], maximumStones[recent][3]) + 3;
        
        maximumStones.push_back({curStone[0], curStone[1], curStone[2], curStone[3]});
    }
    
    std::cout << (maximumStones.size() % 2 == 1 ? "SK" : "CY") << '\n';

    return 0;
}
