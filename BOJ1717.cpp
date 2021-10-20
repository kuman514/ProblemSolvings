#include <iostream>
#include <vector>

// Solving BOJ 1717

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
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> parent(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    // Get commands
    for (int j = 0; j < m; j++) {
        int command, a, b;
        std::cin >> command >> a >> b;
        
        switch (command) {
            case 0:
                addUnion(a, b, parent);
                break;
            case 1:
                std::cout << (hasSameParent(a, b, parent) ? "YES\n" : "NO\n");
                break;
        }
    }
    
    return 0;
}
