#include <iostream>
#include <vector>

// Solving BOJ 16395

int main(void) {
    std::vector<int> triangleRow(31, 0);
    triangleRow[0] = 1;
    
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i < n; i++) {
        std::vector<int> curTriangleRow;
        curTriangleRow.push_back(1);
        for (int j = 1; j <= i; j++) {
            curTriangleRow.push_back(triangleRow[j - 1] + triangleRow[j]);
        }
        curTriangleRow.push_back(1);
        
        for (int j = 0; j <= i; j++) {
            triangleRow[j] = curTriangleRow[j];
        }
    }
    
    std::cout << triangleRow[k - 1] << '\n';

    return 0;
}
