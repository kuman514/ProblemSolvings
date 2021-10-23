#include <iostream>
#include <vector>

// Solving BOJ 10775

int findParent(int cur, std::vector<int>& parent) {
    if (cur == parent[cur]) {
        return cur;
    } else {
        // Update it's parent if not updated yet
        parent[cur] = findParent(parent[cur], parent);
        return parent[cur];
    }
}

void addUnion(int org, int dst, std::vector<int>& parent) {
    const int start = (org <= dst) ? org : dst;
    const int end = (org <= dst) ? dst : org;
    
    const int superSet = findParent(start, parent);
    const int subSet = findParent(end, parent);
    
    parent[subSet] = superSet;
}

bool hasSameParent(int org, int dst, std::vector<int>& parent) {
    const int start = (org <= dst) ? org : dst;
    const int end = (org <= dst) ? dst : org;
    
    const int startParent = findParent(start, parent);
    const int endParent = findParent(end, parent);
    
    return (startParent == endParent);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get input
    int g, p;
    std::cin >> g;
    std::cin >> p;
    
    // Initialize gates
    std::vector<int> gateParent;
    std::vector<bool> docked(g + 1, false);
    for (int i = 0; i <= g; i++) {
        gateParent.push_back(i);
    }
    
    // Get plane's maximum docking gate
    bool closed = false;
    int dockCnt = 0;
    for (int i = 0; i < p && !closed; i++) {
        int maxGate;
        std::cin >> maxGate;
        
        // Dock a plane as highest as it can
        int finalGate = findParent(maxGate, gateParent);
        
        if (finalGate == 0 || docked[finalGate]) {
            closed = true;
            continue;
        }
        
        docked[finalGate] = true;
        dockCnt++;
        
        // Set alternative gate that a plane can dock
        int altGate = findParent(finalGate - 1, gateParent);
        gateParent[finalGate] = altGate;
        gateParent[maxGate] = altGate;
    }
    
    std::cout << dockCnt << '\n';
    
    return 0;
}
