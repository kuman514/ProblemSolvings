#include <iostream>
#include <vector>

// Solving BOJ 10844

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector< std::vector<long long> > steps;
    
    int n;
    std::cin >> n;
    
    /*
        row: current length
        column: starting number
        
    	    0 1 2 3 4 5 6 7 8 9
    	-----------------------
    	1 | 1 1 1 1 1 1 1 1 1 1
    	2 | 1 2 2 2 2 2 2 2 2 1
    	3 | 2 3 4 4 4 4 4 4 3 2
    
    	r | [r-1][c-1] + [r-1][c+1]
    */
    
    steps.push_back(std::vector<long long>(10, 1));
    for (int i = 1; i < n; i++) {
        steps.push_back(std::vector<long long>());
        
        steps[i].push_back(steps[i - 1][1] % 1000000000);
        for (int j = 1; j < 9; j++) {
            steps[i].push_back((steps[i - 1][j - 1] + steps[i - 1][j + 1]) % 1000000000);
        }
        steps[i].push_back(steps[i - 1][8] % 1000000000);
    }
    
    long long sum = 0;
    for (int i = 1; i <= 9; i++) {
        sum += steps[n - 1][i];
        sum %= 1000000000;
    }
    
    std::cout << sum << '\n';

    return 0;
}
