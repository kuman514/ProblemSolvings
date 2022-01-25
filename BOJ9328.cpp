#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 9328

void penetrateOffice() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // Get size
    int h, w;
    std::cin >> h >> w;
    
    // Get office map
    std::vector< std::vector<char> > office(h, std::vector<char>(w, '.'));
    std::vector< std::pair<int, int> > checkpoints;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> office[i][j];
            
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                if (office[i][j] == '.') {
                    checkpoints.push_back({i, j});
                }
            }
        }
    }
    
    // Get keys
    std::string keys;
    std::cin >> keys;
    std::vector<bool> hasKey(26, false);
    if (keys[0] != '0') {
        for (int i = 0; i < keys.length(); i++) {
            hasKey[static_cast<int>(keys[i] - 'a')] = true;
        }
    }
    
    // Penetrate office and capture documents
    int documents = 0;
    for (int i = 0; i < checkpoints.size(); i++) {
        std::queue< std::pair<int, int> > next;
        next.push(checkpoints[i]);
        
        while (!next.empty()) {
        }
    }
    
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        penetrateOffice();
    }

    return 0;
}
