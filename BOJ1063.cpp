#include <iostream>
#include <string>

// Solving BOJ 1063

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    std::string king;
    std::string stone;
    int n;
    
    std::cin >> king >> stone >> n;
    
    for (int i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        
        int dirX = 0;
        int dirY = 0;
        for (int j = 0; j < command.length(); j++) {
            switch (command[j]) {
                case 'L':
                    dirX -= 1;
                    break;
                case 'R':
                    dirX += 1;
                    break;
                case 'T':
                    dirY += 1;
                    break;
                case 'B':
                    dirY -= 1;
                    break;
            }
        }
        
        std::string nextKing(king);
        std::string nextStone(stone);
        
        nextKing[0] += dirX;
        nextKing[1] += dirY;
        
        if (nextStone[0] == nextKing[0] && nextStone[1] == nextKing[1]) {
            nextStone[0] += dirX;
            nextStone[1] += dirY;
        }
        
        if (('A' <= nextKing[0] && nextKing[0] <= 'H') && ('1' <= nextKing[1] && nextKing[1] <= '8') && ('A' <= nextStone[0] && nextStone[0] <= 'H') && ('1' <= nextStone[1] && nextStone[1] <= '8')) {
            king = nextKing;
            stone = nextStone;
        }
    }
    
    std::cout << king << '\n' << stone << '\n';
    
    return 0;
}
