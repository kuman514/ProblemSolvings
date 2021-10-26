#include <iostream>
#include <vector>

// Implementing CCW for BOJ 11758

int ccwDirection(std::pair<int, int>& A, std::pair<int, int>& B, std::pair<int, int>& C) {
    /*
        vector v = (m1, m2, m3)
        vector u = (n1, n2, n3)
        
        vector i = (1, 0, 0)
        vector j = (0, 1, 0)
        vector k = (0, 0, 1)
        
        vector v X vector u
          |  i  j  k |
        = | m1 m2 m3 | = | m2 m3 | i - | m1 m3 | j + | m1 m2 | k
          | n1 n2 n3 |   | n2 n3 |     | n1 n3 |     | n1 n2 |
        = (m2 * n3 - m3 * n2, m3 * n1 - m1 * n3, m1 * n2 - m2 * n1)
        
        Since vector v' = (m1, m2, 0) and vector u' = (n1, n2, 0)
        vector v' X vector u'
          |  i  j  k |
        = | m1 m2  0 | = | m2  0 | i - | m1  0 | j + | m1 m2 | k
          | n1 n2  0 |   | n2  0 |     | n1  0 |     | n1 n2 |
        = (0, 0, m1 * n2 - m2 * n1)
        
        vector A = (a1, a2, 0) :: first
        vector B = (b1, b2, 0) :: middle
        vector C = (c1, c2, 0) :: second
        
        vector B->A = (a1 - b1, a2 - b2, 0)
        vector B->C = (c1 - b1, c2 - b2, 0)
        
        vector B->A X vector B->C
        = (0, 0, (a1 - b1) * (c2 - b2) - (a2 - b2) * (c1 - b1))
        
        (a1 - b1) * (c2 - b2) - (a2 - b2) * (c1 - b1) > 0  :: clockwise
        (a1 - b1) * (c2 - b2) - (a2 - b2) * (c1 - b1) == 0 :: linear
        (a1 - b1) * (c2 - b2) - (a2 - b2) * (c1 - b1) < 0  :: counterclockwise
    */
    
    long long a1 = static_cast<long long>(A.first);
    long long a2 = static_cast<long long>(A.second);
    long long b1 = static_cast<long long>(B.first);
    long long b2 = static_cast<long long>(B.second);
    long long c1 = static_cast<long long>(C.first);
    long long c2 = static_cast<long long>(C.second);
    
    long long result = (a1 - b1) * (c2 - b2) - (a2 - b2) * (c1 - b1);
    if (result > 0) {
        // clockwise
        return -1;
    } else if (result == 0) {
        // linear
        return 0;
    } else if (result < 0) {
        // counterclockwise
        return 1;
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get input
    std::pair<int, int> first, middle, second;
    std::cin >> first.first >> first.second >> middle.first >> middle.second >> second.first >> second.second;
    std::cout << ccwDirection(first, middle, second) << '\n';
    
    return 0;
}
