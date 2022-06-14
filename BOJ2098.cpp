#include <iostream>
#include <vector>

// Solving BOJ 2098

const int INF = 16000001;
const int NOT_VISITED = -1;

int travelingSalesperson(
    int n,
    int currentCity,
    int visited,
    std::vector< std::vector<int> >& weight,
    std::vector< std::vector<int> >& minCost,
    std::vector<int>& bitMaskValues,
    int fullyVisited
) {
    // Already visited?
    if (minCost[currentCity][visited] != NOT_VISITED) {
        return minCost[currentCity][visited];
    }
    
    // If fully visited
    if (visited == fullyVisited) {
        if (weight[currentCity][0] > 0) {
            return weight[currentCity][0];
        } else {
            return INF;
        }
    }
    
    int tmpCost = INF;
    for (int i = 0; i < n; i++) {
        // Already visited?
        if (visited & bitMaskValues[i]) {
            continue;
        }
        
        // No route?
        if (weight[currentCity][i] == 0) {
            continue;
        }
        
        int curCost = travelingSalesperson(
            n,
            i,
            visited | bitMaskValues[i],
            weight,
            minCost,
            bitMaskValues,
            fullyVisited
        );
        
        int totalCost;
        if (curCost >= INF) {
            totalCost = INF;
        } else {
            totalCost = weight[currentCity][i] + curCost;
        }
        
        if (tmpCost > totalCost) {
            tmpCost = totalCost;
        }
    }
    
    minCost[currentCity][visited] = tmpCost;
    return tmpCost;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    // Get weight of i -> j
    std::vector< std::vector<int> > weight(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> weight[i][j];
        }
    }
    
    // Initialize bit mask
    int bitmask = 1;
    int fullyVisited = 0;
    std::vector<int> bitMaskValues(n, 0);
    for (int i = 0; i < n; i++) {
        bitMaskValues[i] |= bitmask;
        fullyVisited |= bitmask;
        bitmask <<= 1;
    }
    
    // Initialize minimum costs
    std::vector< std::vector<int> > minCost(n, std::vector<int>(fullyVisited + 1, NOT_VISITED));
    
    std::cout << travelingSalesperson(
        n,
        0,
        1,
        weight,
        minCost,
        bitMaskValues,
        fullyVisited
    ) << '\n';
    
    return 0;
}
