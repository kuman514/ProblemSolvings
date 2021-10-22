#include <iostream>
#include <vector>

// Solving BOJ 1976

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
    std::cin >> n;
    std::cin >> m;
    
    std::vector<int> parent(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    // Get connection
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int input;
            std::cin >> input;
            
            if (j <= i) {
                continue;
            }
            
            if (input == 1) {
                addUnion(i, j, parent);
            }
        }
    }
    
    // Determine
    int city = -1;
    bool available = true;
    for (int i = 0; i < m; i++) {
        int input;
        std::cin >> input;
        
        if (city == -1) {
            city = findParent(input, parent);
        } else if (!hasSameParent(city, input, parent)) {
            available = false;
        }
    }
    
    std::cout << (available ? "YES" : "NO") << '\n';
    
    return 0;
}
