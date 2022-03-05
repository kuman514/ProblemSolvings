#include <iostream>
#include <string>

// Solving BOJ 1593

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    // Get sizes
    int g, sLen;
    std::cin >> g >> sLen;
    
    // Get strings
    std::string w, s;
    std::cin >> w;
    std::cin >> s;
    
    // String letter counter
    // 0~25: A~Z, 26~51: a~z
    int wContain[52] = {0,};
    int sContain[52] = {0,};
    
    // Count letters in w
    for (int i = 0; i < g; i++) {
        if ('A' <= w[i] && w[i] <= 'Z') {
            wContain[static_cast<int>(w[i] - 'A')]++;
        } else if ('a' <= w[i] && w[i] <= 'z') {
            wContain[static_cast<int>(w[i] - 'a') + 26]++;
        }
    }
    
    // Count letters in s[start, end)
    int start = 0;
    int end = start + 1;
    
    // Insert the first into sliding window
    if ('A' <= s[start] && s[start] <= 'Z') {
        sContain[static_cast<int>(s[start] - 'A')]++;
    } else if ('a' <= s[start] && s[start] <= 'z') {
        sContain[static_cast<int>(s[start] - 'a') + 26]++;
    }
    
    int totalPairs = 0;
    while (start < end) {
        const int curLen = end - start;
        
        // Check identical
        bool identical = true;
        for (int i = 0; i < 52; i++) {
            if (wContain[i] != sContain[i]) {
                identical = false;
                break;
            }
        }
        
        if (identical) {
            totalPairs++;
        }
        
        if (end >= sLen) {
            // Eject s[start] from sliding window
            if ('A' <= s[start] && s[start] <= 'Z') {
                sContain[static_cast<int>(s[start] - 'A')]--;
            } else if ('a' <= s[start] && s[start] <= 'z') {
                sContain[static_cast<int>(s[start] - 'a') + 26]--;
            }
            start++;
        } else if (curLen < g) {
            // Insert s[end] into sliding window
            if ('A' <= s[end] && s[end] <= 'Z') {
                sContain[static_cast<int>(s[end] - 'A')]++;
            } else if ('a' <= s[end] && s[end] <= 'z') {
                sContain[static_cast<int>(s[end] - 'a') + 26]++;
            }
            end++;
        } else {
            // Eject s[start] from sliding window
            if ('A' <= s[start] && s[start] <= 'Z') {
                sContain[static_cast<int>(s[start] - 'A')]--;
            } else if ('a' <= s[start] && s[start] <= 'z') {
                sContain[static_cast<int>(s[start] - 'a') + 26]--;
            }
            start++;
            
            // Insert s[end] into sliding window
            if ('A' <= s[end] && s[end] <= 'Z') {
                sContain[static_cast<int>(s[end] - 'A')]++;
            } else if ('a' <= s[end] && s[end] <= 'z') {
                sContain[static_cast<int>(s[end] - 'a') + 26]++;
            }
            end++;
        }
    }
    
    std::cout << totalPairs << '\n';

    return 0;
}
