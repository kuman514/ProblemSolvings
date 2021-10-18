#include <iostream>
#include <vector>

// Solving BOJ 11049
const long long INF = 500LL * 500LL * 500LL * 500LL + 1LL;

struct SizeInfo {
    int rows;
    int cols;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    // Get input
    int n;
    std::cin >> n;
    
    // Get matrix sizes
    std::vector<SizeInfo> matrixSizes;
    for (int i = 0; i < n; i++) {
        int r, c;
        std::cin >> r >> c;
        matrixSizes.push_back({r, c});
    }
    
    // Init before calculation
    std::vector< std::vector<long long> > calcCounts(n + 1, std::vector<long long>(n, INF));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            calcCounts[i][j] = 0LL;
        }
    }
    
    // Calculate minimum calculation counts
    // row: length, col: start index
    for (int length = 2; length <= n; length++) {
        for (int start = 0; start <= n - length; start++) {
            const int end = start + length - 1;
            
            for (int rightStart = start + 1; rightStart <= end; rightStart++) {
                const int leftEnd = rightStart - 1;
                
                const int leftLength = leftEnd - start + 1;
                const int rightLength = end - rightStart + 1;
                
                const long long prevCount = calcCounts[leftLength][start] + calcCounts[rightLength][rightStart];
                SizeInfo leftSize({matrixSizes[start].rows, matrixSizes[leftEnd].cols});
                SizeInfo rightSize({matrixSizes[rightStart].rows, matrixSizes[end].cols});
                const long long curCount = leftSize.rows * leftSize.cols * rightSize.cols;
                
                const long long finalCount = prevCount + curCount;
                if (calcCounts[length][start] > finalCount) {
                    calcCounts[length][start] = finalCount;
                }
            }
        }
    }
    
    std::cout << calcCounts[n][0] << '\n';
    
    return 0;
}
