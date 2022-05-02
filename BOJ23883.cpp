#include <iostream>
#include <vector>
#include <queue>

// Solving BOJ 23883

struct ArrayNumber {
    int value;
    int index;
};

class Comparison {
    public:
        bool operator() (const ArrayNumber& lhs, const ArrayNumber& rhs) const {
            return (lhs.value < rhs.value);
        }
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get size and swap count
    int n, k;
    std::cin >> n >> k;
    
    // Get numbers
    std::vector<int> currentArray(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> currentArray[i];
    }
    
    // Push each number and its index to get the biggest number of each iteration
    std::priority_queue<ArrayNumber, std::vector<ArrayNumber>, Comparison> biggest;
    for (int i = 0; i < n; i++) {
        biggest.push({currentArray[i], i});
    }
    
    // Simulate selection sort while currentSwaps < k
    int currentSwaps = 0;
    int kSwappedNum1 = -1;
    int kSwappedNum2 = -1;
    for (int last = n - 1; last >= 1 && currentSwaps < k; last--) {
        ArrayNumber biggestNum = biggest.top();
        biggest.pop();
        
        while (biggestNum.index > last) {
            biggestNum = biggest.top();
            biggest.pop();
        }
        
        // If picked value is bigger
        if (biggestNum.value > currentArray[last] && last != biggestNum.index) {
            // Swap currentArray[last] <-> currentArray[biggestNum.index]
            int swapTmp = currentArray[biggestNum.index];
            currentArray[biggestNum.index] = currentArray[last];
            currentArray[last] = swapTmp;
            currentSwaps++;
            
            if (currentSwaps == k) {
                kSwappedNum1 = (currentArray[biggestNum.index] < currentArray[last] ? currentArray[biggestNum.index] : currentArray[last]);
                kSwappedNum2 = (currentArray[biggestNum.index] < currentArray[last] ? currentArray[last] : currentArray[biggestNum.index]);
            }
        }
        
        biggest.push({currentArray[biggestNum.index], biggestNum.index});
    }
    
    if (currentSwaps >= k) {
        std::cout << kSwappedNum1 << ' ' << kSwappedNum2 << '\n';
    } else {
        std::cout << "-1\n";
    }

    return 0;
}
