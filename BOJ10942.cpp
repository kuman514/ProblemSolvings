#include <iostream>
#include <vector>

// Solving BOJ 10942

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    // Get input
    int n;
    std::cin >> n;
    
    // Get elements
    std::vector<int> elements;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        elements.push_back(input);
    }
    
    // Determine palindrome
    /*
        Expected rules
        
        1. All queries with only one character are palindrome.
        2. If a query is like "[START Character] (Middle characters) [END Character]",
            2-1. check [START Character] == [END Character] first,
            2-2. then check isPalindrome[start index of middle][end index of middle].
    */
    std::vector< std::vector<bool> > isPalindrome(n + 1, std::vector<bool>(n + 1, false));
    for (int start = n; start >= 0; start--) {
        for (int end = start; end <= n; end++) {
            const int i = start - 1;
            const int j = end - 1;
            if (elements[i] == elements[j]) {
                const int length = end - start + 1;
                if (length < 3) {
                    isPalindrome[start][end] = true;
                } else {
                    isPalindrome[start][end] = isPalindrome[start + 1][end - 1];
                }
            } else {
                isPalindrome[start][end] = false;
            }
        }
    }
    
    // Get queries
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int start, end;
        std::cin >> start >> end;
        std::cout << (isPalindrome[start][end] ? 1 : 0) << '\n';
    }
    
    return 0;
}
