#include <iostream>
#include <vector>

// Solving BOJ 17404

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    // Get weights
    std::vector< std::vector<int> > weight(n, std::vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> weight[i][j];
        }
    }
    
    // Pick a first color and calculate cost
    const int INF = 100000000;
    // [First Color][Line][Color Selection]
    std::vector< std::vector< std::vector<int> > > cost(3, std::vector< std::vector<int> >(n, std::vector<int>(3, INF)));
    for (int first = 0; first < 3; first++) {
        cost[first][0][first] = weight[0][first];
        
        for (int i = 1; i < n - 1; i++) {
            int tmpCost[3];
            
            // Red
            tmpCost[0] = std::min(cost[first][i - 1][1], cost[first][i - 1][2]) + weight[i][0];
            
            // Green
            tmpCost[1] = std::min(cost[first][i - 1][0], cost[first][i - 1][2]) + weight[i][1];
            
            // Blue
            tmpCost[2] = std::min(cost[first][i - 1][0], cost[first][i - 1][1]) + weight[i][2];
            
            cost[first][i][0] = tmpCost[0];
            cost[first][i][1] = tmpCost[1];
            cost[first][i][2] = tmpCost[2];
        }
        
        // Final line
        int finalTmpCost[3];
        finalTmpCost[0] = std::min(cost[first][n - 2][1], cost[first][n - 2][2]) + weight[n - 1][0];
        finalTmpCost[1] = std::min(cost[first][n - 2][0], cost[first][n - 2][2]) + weight[n - 1][1];
        finalTmpCost[2] = std::min(cost[first][n - 2][0], cost[first][n - 2][1]) + weight[n - 1][2];
        
        switch (first) {
            case 0:
                cost[first][n - 1][1] = finalTmpCost[1];
                cost[first][n - 1][2] = finalTmpCost[2];
                break;
            case 1:
                cost[first][n - 1][0] = finalTmpCost[0];
                cost[first][n - 1][2] = finalTmpCost[2];
                break;
            case 2:
                cost[first][n - 1][0] = finalTmpCost[0];
                cost[first][n - 1][1] = finalTmpCost[1];
                break;
        }
    }
    
    // Get lowest cost
    int lowestCost = INF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (lowestCost > cost[i][n - 1][j]) {
                lowestCost = cost[i][n - 1][j];
            }
        }
    }
    
    std::cout << lowestCost << '\n';
    
    return 0;
}
