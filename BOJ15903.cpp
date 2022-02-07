#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Solving BOJ 15903

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::priority_queue<long long> cards;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        cards.push(1LL * (-input));
    }

    for (int i = 0; i < m; i++) {
        long long first = -(cards.top());
        cards.pop();
        long long second = -(cards.top());
        cards.pop();

        long long sum = first + second;
        cards.push(-sum);
        cards.push(-sum);
    }

    long long totalSum = 0LL;
    while (!cards.empty()) {
        totalSum += -(cards.top());
        cards.pop();
    }

    std::cout << totalSum << '\n';

    return 0;
}
