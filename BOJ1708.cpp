#include <iostream>
#include <vector>
#include <algorithm>

// Solving BOJ 1708

std::pair<int, int> firstPoint;

int clockwise(std::pair<int, int>& p1, std::pair<int, int>& p2, std::pair<int, int>& p3) {
    /*
        first point: (x1, y1)
        second point: (x2, y2)
        third point: (x3, y3)
        |  1  1  1 |
        | x1 x2 x3 | = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
        | y1 y2 y3 |
    */
    
    long long result = 1LL * p1.first * (p2.second - p3.second)
                    + 1LL * p2.first * (p3.second - p1.second)
                    + 1LL * p3.first * (p1.second - p2.second);
    
    if (result > 0) {
        // Counter-clockwise
        return 1;
    } else if (result < 0) {
        // Clockwise
        return -1;
    } else if (result == 0) {
        // Linear
        return 0;
    }
}

bool initSort(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second > p2.second) {
        return false;
    } else if (p1.first < p2.first) {
        return true;
    }
    
    return false;
}

bool sortBySlope(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    int dx1 = p1.first - firstPoint.first;
    int dy1 = p1.second - firstPoint.second;
    int dx2 = p2.first - firstPoint.first;
    int dy2 = p2.second - firstPoint.second;
    
    // Sort by crossproduct
    long long crossproduct = 1LL * dx1 * dy2 - 1LL * dy1 * dx2;
    if (crossproduct > 0) {
        return true;
    } else if (crossproduct < 0) {
        return false;
    }
    
    // Sort by distance: firstPoint <-> currentPoint
    long long dist1 = 1LL * dy1 * dy1 + 1LL * dx1 * dx1;
    long long dist2 = 1LL * dx2 * dx2 + 1LL * dy2 * dy2;
    if (dist1 < dist2) {
        return true;
    }
    
    return false;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // first: x, second: y
    std::vector< std::pair<int, int> > points;
    points.reserve(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        points.push_back({x, y});
    }
    
    // Initial sort
    std::sort(points.begin(), points.end(), initSort);
    
    // Sort by slope
    firstPoint = points[0];
    std::sort(points.begin(), points.end(), sortBySlope);
    
    // Graham scan
    std::vector<int> cnvHullPntIndex;
    cnvHullPntIndex.push_back(0);
    cnvHullPntIndex.push_back(1);
    int i = 2;
    while (i <= points.size()) {
        // first: back - 1, middle: back, latest: tmp
        int tmp = i % points.size();
        std::pair<int, int> p1 = points[cnvHullPntIndex[cnvHullPntIndex.size() - 2]];
        std::pair<int, int> p2 = points[cnvHullPntIndex.back()];
        std::pair<int, int> p3 = points[tmp];
        
        if (clockwise(p1, p2, p3) == 1) {
            // If counterclockwise, add latest to back
            cnvHullPntIndex.push_back(tmp);
            i++;
        } else {
            // If not, remove middle
            cnvHullPntIndex.pop_back();
            
            // If less than 2 remain, add latest to back
            if (cnvHullPntIndex.size() < 2) {
                cnvHullPntIndex.push_back(tmp);
                i++;
            }
        }
    }
    
    std::cout << (cnvHullPntIndex.size() - 1) << '\n';
    
    return 0;
}
