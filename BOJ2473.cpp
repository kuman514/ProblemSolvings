#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 2473

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // Get input
    int n;
    std::cin >> n;
    
    std::vector<long long> arr;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        arr.push_back(input);
    }
    
    std::sort(arr.begin(), arr.end());
    
    long long minDiff = 1000000000LL * 3LL + 1LL;
    long long closest[3] = {0LL,};
    bool exactlyZero = false;
    
    for (int i = 0; i < n - 2 && !exactlyZero; i++) {
        // Using Two-pointer solution
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            long long tmpDiff = arr[i] + arr[left] + arr[right];
            long long finalDiff = std::abs(tmpDiff);
            
            if (minDiff > finalDiff) {
                minDiff = finalDiff;
                closest[0] = arr[i];
                closest[1] = arr[left];
                closest[2] = arr[right];
            }
            
            if (tmpDiff == 0) {
                // If exactly 0, no more mix
                exactlyZero = true;
                break;
            } else if (tmpDiff < 0) {
                left++;
            } else if (tmpDiff > 0) {
                right--;
            }
        }
    }
    
    std::cout << closest[0] << ' ' << closest[1] << ' ' << closest[2] << '\n';

    return 0;
}
