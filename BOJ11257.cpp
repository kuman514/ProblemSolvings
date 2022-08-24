#include <iostream>
#include <vector>
#include <string>

// Solving BOJ 11257

struct TestTaker {
    int id;
    int strategyScore;
    int manageScore;
    int techScore;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<TestTaker> testTaker;
    for (int i = 0; i < n; i++) {
        int id;
        int strategyScore;
        int manageScore;
        int techScore;
        
        std::cin >> id;
        std::cin >> strategyScore;
        std::cin >> manageScore;
        std::cin >> techScore;
        
        testTaker.push_back({id, strategyScore, manageScore, techScore});
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << testTaker[i].id << ' ';
        std::cout << (testTaker[i].strategyScore + testTaker[i].manageScore + testTaker[i].techScore) << ' ';
        
        if (testTaker[i].strategyScore + testTaker[i].manageScore + testTaker[i].techScore < 55) {
            std::cout << "FAIL" << '\n';
        } else if (testTaker[i].strategyScore < (35 * 0.3)) {
            std::cout << "FAIL" << '\n';
        } else if (testTaker[i].manageScore < (25 * 0.3)) {
            std::cout << "FAIL" << '\n';
        } else if (testTaker[i].techScore < (40 * 0.3)) {
            std::cout << "FAIL" << '\n';
        } else {
            std::cout << "PASS" << '\n';
        }
    }
    
    return 0;
}
