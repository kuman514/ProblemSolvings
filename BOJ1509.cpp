#include <iostream>
#include <vector>

// Solving BOJ 1509

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get sentence
    std::string sentence;
    std::cin >> sentence;
    
    // Dynamic programming matrix
    std::vector< std::vector<bool> > palindrome(sentence.length(), std::vector<bool>(sentence.length(), false));
    for (int start = sentence.length() - 1; start >= 0; start--) {
        for (int end = start; end < sentence.length(); end++) {
            int curLen = end - start + 1;
            switch (curLen) {
                case 1:
                    palindrome[start][end] = true;
                    break;
                case 2:
                    if (sentence[start] == sentence[end]) {
                        palindrome[start][end] = true;
                    } else {
                        palindrome[start][end] = false;
                    }
                    break;
                default:
                    if (sentence[start] == sentence[end]) {
                        palindrome[start][end] = palindrome[start + 1][end - 1];
                    } else {
                        palindrome[start][end] = false;
                    }
                    break;
            }
        }
    }
    
    // Calculate split from start
    std::vector<int> splits(sentence.length(), 0);
    for (int start = sentence.length() - 1; start >= 0; start--) {
        int minimumSplits = sentence.length();
        
        for (int end = sentence.length() - 1; end >= start; end--) {
            if (palindrome[start][end]) {
                if (end + 1 >= sentence.length()) {
                    minimumSplits = 1;
                } else {
                    if (minimumSplits > splits[end + 1] + 1) {
                        minimumSplits = splits[end + 1] + 1;
                    }
                }
            }
        }
        
        splits[start] = minimumSplits;
    }
    
    std::cout << splits[0] << '\n';
    
    return 0;
}
