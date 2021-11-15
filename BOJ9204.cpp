#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solving BOJ 9204

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get input
    int t;
    std::cin >> t;
    
    for (int c = 0; c < t; c++) {
        char x1, x2;
        int y1, y2;
        
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        // first: row, second: col
        std::pair<int, int> start(8 - y1, static_cast<int>(x1 - 'A'));
        std::pair<int, int> end(8 - y2, static_cast<int>(x2 - 'A'));
        
        // Check possibility
        int diagS = start.first + start.second;
        int diagE = end.first + end.second;
        if (diagS % 2 != diagE % 2) {
            std::cout << "Impossible\n";
            continue;
        }
        
        // Check path directly to goal
        if (start.first == end.first && start.second == end.second) {
            std::cout << 0 << ' ' << static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << '\n';
            continue;
        }
        
        if (diagS == diagE) {
            std::cout << 1 << ' ' << static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' << static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            continue;
        }
        
        int diagS2 = 7 - start.first + start.second;
        int diagE2 = 7 - end.first + end.second;
        if (diagS2 == diagE2) {
            std::cout << 1 << ' ' << static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' << static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            continue;
        }
        
        // Check path to goal
        bool found = false;
        int shift = 0;
        
        shift = 1;
        while (!found) {
            if (start.first - shift < 0 || start.first - shift >= 8) {
                break;
            }
            
            if (start.second - shift < 0 || start.second - shift >= 8) {
                break;
            }
            
            int altDiagS = start.first - shift + start.second - shift;
            if (altDiagS == diagE) {
                found = true;
                std::cout << 2 << ' ' <<
                    static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' <<
                    static_cast<char>((start.second - shift) + 'A') << ' ' << (8 - (start.first - shift)) << ' ' <<
                    static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            }
            
            shift++;
        }
        
        shift = 1;
        while (!found) {
            if (start.first + shift < 0 || start.first + shift >= 8) {
                break;
            }
            
            if (start.second + shift < 0 || start.second + shift >= 8) {
                break;
            }
            
            int altDiagS = start.first + shift + start.second + shift;
            if (altDiagS == diagE) {
                found = true;
                std::cout << 2 << ' ' <<
                    static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' <<
                    static_cast<char>((start.second + shift) + 'A') << ' ' << (8 - (start.first + shift)) << ' ' <<
                    static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            }
            
            shift++;
        }
        
        shift = 1;
        while (!found) {
            if (start.first + shift < 0 || start.first + shift >= 8) {
                break;
            }
            
            if (start.second - shift < 0 || start.second - shift >= 8) {
                break;
            }
            
            int altDiagS = 7 - (start.first + shift) + (start.second - shift);
            if (altDiagS == diagE2) {
                found = true;
                std::cout << 2 << ' ' <<
                    static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' <<
                    static_cast<char>((start.second - shift) + 'A') << ' ' << (8 - (start.first + shift)) << ' ' <<
                    static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            }
            
            shift++;
        }
        
        shift = 1;
        while (!found) {
            if (start.first - shift < 0 || start.first - shift >= 8) {
                break;
            }
            
            if (start.second + shift < 0 || start.second + shift >= 8) {
                break;
            }
            
            int altDiagS = 7 - (start.first - shift) + (start.second + shift);
            if (altDiagS == diagE2) {
                found = true;
                std::cout << 2 << ' ' <<
                    static_cast<char>(start.second + 'A') << ' ' << (8 - start.first) << ' ' <<
                    static_cast<char>((start.second + shift) + 'A') << ' ' << (8 - (start.first - shift)) << ' ' <<
                    static_cast<char>(end.second + 'A') << ' ' << (8 - end.first) << '\n';
            }
            
            shift++;
        }
    }

    return 0;
}
