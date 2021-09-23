#include <iostream>
#include <vector>

// Solving BOJ 2263

struct info {
    int parent;
    int lchild;
    int rchild;
};

// inorder / postorder range: [start, end]
void parseForPreorder(int inStart, int inEnd, int postStart, int postEnd, std::vector<int>& inorder, std::vector<int>& postorder, std::vector<info>& nodeInfo, std::vector<int>& inorderPosition) {
    //std::cout << "current node: " << postorder[postEnd] << '\n';
    
    if (inEnd <= inStart || postEnd <= postStart) {
        //std::cout << "LEAF\n\n";
        return;
    }
    
    int parentNum = postorder[postEnd];
    
    // Get inorder pivot
    int inorderPivot = inorderPosition[parentNum];
    
    // inorder range [inStart, inorderPivot) and (inorderPivot, inEnd]
    int inLStart = inStart;
    int inLEnd = inorderPivot - 1;
    int inRStart = inorderPivot + 1;
    int inREnd = inEnd;
    
    /*
    std::cout << "inorder left:  [" << inLStart << ", " << inLEnd << "]" << ((inLEnd >= inLStart) ? "\n" : " (Invalid)\n");
    std::cout << "inorder right: [" << inRStart << ", " << inREnd << "]" << ((inREnd >= inRStart) ? "\n" : " (Invalid)\n");
    */
    
    // Get postorder pivot
    int postorderPivot = postStart + inLEnd - inLStart + 1;
    
    // postorder range [postStart, postorderPivot) and [postorderPivot, postEnd)
    int postLStart = postStart;
    int postLEnd = postorderPivot - 1;
    int postRStart = postorderPivot;
    int postREnd = postEnd - 1;
    
    /*
    std::cout << "postorder left:  [" << postLStart << ", " << postLEnd << "]" << ((postLEnd >= postLStart) ? "\n" : " (Invalid)\n");
    std::cout << "postorder right: [" << postRStart << ", " << postREnd << "]" << ((postREnd >= postRStart) ? "\n" : " (Invalid)\n");
    std::cout << '\n';
    */
    
    // Proceed to next
    if (inLEnd >= inLStart && postLEnd >= postLStart) {
        nodeInfo[parentNum].lchild = postorder[postLEnd];
        nodeInfo[nodeInfo[parentNum].lchild].parent = parentNum;
        
        if (inLEnd > inLStart && postLEnd > postLStart) {
            parseForPreorder(inLStart, inLEnd, postLStart, postLEnd, inorder, postorder, nodeInfo, inorderPosition);
        }
    }
    
    if (inREnd >= inRStart && postREnd >= postRStart) {
        nodeInfo[parentNum].rchild = postorder[postREnd];
        nodeInfo[nodeInfo[parentNum].rchild].parent = parentNum;
        
        if (inREnd > inRStart && postREnd > postRStart) {
            parseForPreorder(inRStart, inREnd, postRStart, postREnd, inorder, postorder, nodeInfo, inorderPosition);
        }
    }
}

void paintPreorder(int current, std::vector<int>& preorder, std::vector<info>& nodeInfo) {
    preorder.push_back(current);
    
    if (nodeInfo[current].lchild != -1) {
        paintPreorder(nodeInfo[current].lchild, preorder, nodeInfo);
    }
    
    if (nodeInfo[current].rchild != -1) {
        paintPreorder(nodeInfo[current].rchild, preorder, nodeInfo);
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<info> nodeInfo(n, {-1, -1, -1});
    std::vector<int> inorder;
    std::vector<int> postorder;
    std::vector<int> inorderPosition(n, -1);
    
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        inorder.push_back(input - 1);
        inorderPosition[input - 1] = i;
    }
    
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        postorder.push_back(input - 1);
    }
    
    int root = postorder[n - 1];
    parseForPreorder(0, n - 1, 0, n - 1, inorder, postorder, nodeInfo, inorderPosition);
    
    std::vector<int> preorder;
    paintPreorder(root, preorder, nodeInfo);
    
    for (int i = 0; i < n; i++) {
        std::cout << (preorder[i] + 1) << ((i == n - 1) ? '\n' : ' ');
    }
    
    return 0;
}
