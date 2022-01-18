#include <iostream>
#include <vector>

// Solving BOJ 4256

void searchRelationships(
    std::vector< std::pair<int, int> >& tree,
    std::vector<int>& prefixResult,
    std::vector<int>& infixResult,
    int prefixStart,
    int prefixEnd,
    int infixStart,
    int infixEnd
) {
    int parent = prefixResult[prefixStart];
    
    // Search lchildren range
    int lchildCnt = -1;
    for (int i = infixStart; i <= infixEnd; i++) {
        if (infixResult[i] == parent) {
            break;
        }
        lchildCnt++;
    }
    
    // Get lchildren
    int lchildPrefixStart = prefixStart + 1;
    int lchildPrefixEnd = lchildPrefixStart + lchildCnt;
    int lchildInfixStart = infixStart;
    int lchildInfixEnd = lchildInfixStart + lchildCnt;
    
    // If lchildren exist, search them
    if (lchildCnt >= 0) {
        tree[parent].first = prefixResult[lchildPrefixStart];
        searchRelationships(
            tree,
            prefixResult,
            infixResult,
            lchildPrefixStart,
            lchildPrefixEnd,
            lchildInfixStart,
            lchildInfixEnd
        );
    }
    
    // Get rchildren
    int rchildPrefixStart = lchildPrefixEnd + 1;
    int rchildPrefixEnd = prefixEnd;
    int rchildInfixStart = lchildInfixEnd + 2;
    int rchildInfixEnd = infixEnd;
    
    // If rchildren exist, search them
    if (rchildPrefixStart <= rchildPrefixEnd && rchildInfixStart <= rchildInfixEnd) {
        tree[parent].second = prefixResult[rchildPrefixStart];
        searchRelationships(
            tree,
            prefixResult,
            infixResult,
            rchildPrefixStart,
            rchildPrefixEnd,
            rchildInfixStart,
            rchildInfixEnd
        );
    }
}

void getPostfixResult(
    std::vector< std::pair<int, int> >& tree,
    std::vector<int>& postfixResult,
    int currentNode
) {
    if (tree[currentNode].first > 0) {
        getPostfixResult(
            tree,
            postfixResult,
            tree[currentNode].first
        );
    }
    
    if (tree[currentNode].second > 0) {
        getPostfixResult(
            tree,
            postfixResult,
            tree[currentNode].second
        );
    }
    
    postfixResult.push_back(currentNode);
}

void treeProcess() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> prefixResult(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> prefixResult[i];
    }
    
    std::vector<int> infixResult(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> infixResult[i];
    }
    
    // first: lchild, second: rchild
    std::vector< std::pair<int, int> > tree(n + 1, {0, 0});
    
    // Make tree
    searchRelationships(
        tree,
        prefixResult,
        infixResult,
        0,
        n - 1,
        0,
        n - 1
    );
    
    // Get postfix
    std::vector<int> postfixResult;
    getPostfixResult(
        tree,
        postfixResult,
        prefixResult[0]
    );
    
    for (int i = 0; i < postfixResult.size(); i++) {
        std::cout << postfixResult[i];
        if (i == postfixResult.size() - 1) {
            std::cout << '\n';
        } else {
            std::cout << ' ';
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        treeProcess();
    }
    
    return 0;
}
