#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 1967

struct info {
    int dest;
    int weight;
};

int largestDiameter = 0;

int calculateTreeDiameter(int nodeIndex, std::vector< std::vector<info> > &nodeInfo) {
    // If this node is a leaf
    if (nodeInfo[nodeIndex].size() == 0) {
        return 0;
    }
    
    // Calculate the children's tree diameters
    std::vector<int> childVals;
    std::for_each(nodeInfo[nodeIndex].begin(), nodeInfo[nodeIndex].end(), [&nodeInfo, &childVals](info& childInfo) {
        int calculated = calculateTreeDiameter(childInfo.dest, nodeInfo);
        childVals.push_back(childInfo.weight + calculated);
    });
    
    std::sort(childVals.begin(), childVals.end(), std::greater<int>());
    if (childVals.size() >= 2) {
        // If this node has at least 2 children
        if (childVals[0] + childVals[1] > largestDiameter) {
            largestDiameter = childVals[0] + childVals[1];
        }
    } else if (childVals.size() == 1) {
        // If this node has only 1 child
        if (childVals[0] > largestDiameter) {
            largestDiameter = childVals[0];
        }
    }
    
    return childVals[0];
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector< std::vector<info> > nodeInfo(n + 1, std::vector<info>());
    
    for (int i = 1; i < n; i++) {
        int o, d, w;
        std::cin >> o >> d >> w;
        nodeInfo[o].push_back({d, w});
    }
    
    calculateTreeDiameter(1, nodeInfo);
    std::cout << largestDiameter << '\n';
    
    return 0;
}
