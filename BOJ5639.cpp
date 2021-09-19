#include <iostream>
#include <vector>
#include <string>

// Solving BOJ 5639

struct node {
    int value;
    int lchildIndex;
    int rchildIndex;
};

void printPostfix(int curIndex, std::vector<node>& nodeTree) {
    if (curIndex == -1) {
        return;
    }
    
    if (nodeTree[curIndex].lchildIndex != -1) {
        printPostfix(nodeTree[curIndex].lchildIndex, nodeTree);
    }
    
    if (nodeTree[curIndex].rchildIndex != -1) {
        printPostfix(nodeTree[curIndex].rchildIndex, nodeTree);
    }
    
    std::cout << nodeTree[curIndex].value << '\n';
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int rawInput;
    std::vector<node> nodeTree;
    
    // Get input
    std::cin >> rawInput;
    while (true) {
        int input = rawInput;
        
        if (nodeTree.empty()) {
            // Initial push
            nodeTree.push_back({input, -1, -1});
        } else {
            // Seek child's position and push
            int curIndex = 0;
            bool searching = true;
            while (searching) {
                if (input < nodeTree[curIndex].value) {
                    if (nodeTree[curIndex].lchildIndex == -1) {
                        nodeTree.push_back({input, -1, -1});
                        nodeTree[curIndex].lchildIndex = nodeTree.size() - 1;
                        searching = false;
                    } else {
                        curIndex = nodeTree[curIndex].lchildIndex;
                    }
                } else if (input > nodeTree[curIndex].value) {
                    if (nodeTree[curIndex].rchildIndex == -1) {
                        nodeTree.push_back({input, -1, -1});
                        nodeTree[curIndex].rchildIndex = nodeTree.size() - 1;
                        searching = false;
                    } else {
                        curIndex = nodeTree[curIndex].rchildIndex;
                    }
                }
            }
        }
        
        // Next input
        std::cin >> rawInput;
        if (rawInput == input) {
            break;
        }
    }
    
    printPostfix(0, nodeTree);
    
    return 0;
}
