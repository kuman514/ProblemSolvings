#include <iostream>
#include <vector>

// Solving BOJ 10830

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    long long b;
    std::cin >> n >> b;
    
    // Get matrix input
    std::vector< std::vector< std::vector<int> > > sqMatrixes;
    sqMatrixes.push_back(std::vector< std::vector<int> >());
    
    for (int i = 0; i < n; i++) {
        sqMatrixes[0].push_back(std::vector<int>());
        
        for (int j = 0; j < n; j++) {
            int input;
            std::cin >> input;
            sqMatrixes[0][i].push_back(input);
        }
    }
    
    // Precalculate matrixes squared
    for (int t = 1; t <= 37; t++) {
        sqMatrixes.push_back(std::vector< std::vector<int> >());
        
        for (int i = 0; i < n; i++) {
            sqMatrixes[t].push_back(std::vector<int>());
            
            for (int j = 0; j < n; j++) {
                int newNum = 0;
                for (int k = 0; k < n; k++) {
                    newNum += (sqMatrixes[t - 1][i][k] * sqMatrixes[t - 1][k][j]);
                }
                sqMatrixes[t][i].push_back(newNum % 1000);
            }
        }
    }
    
    // Get mod 2
    std::vector<bool> mod2;
    long long num = b;
    while (num > 0LL) {
        if (num % 2LL == 1) {
            mod2.push_back(true);
        } else {
            mod2.push_back(false);
        }
        
        num /= 2LL;
    }
    
    // Init final result
    std::vector< std::vector<int> > finalResult(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        finalResult[i][i] = 1;
    }
    
    // Get total calculation
    for (int t = 0; t < mod2.size(); t++) {
        if (mod2[t]) {
            std::vector< std::vector<int> > tmpMat;
            
            for (int i = 0; i < n; i++) {
                tmpMat.push_back(std::vector<int>());
                for (int j = 0; j < n; j++) {
                    int newNum = 0;
                    for (int k = 0; k < n; k++) {
                        newNum += (finalResult[i][k] * sqMatrixes[t][k][j]);
                    }
                    tmpMat[i].push_back(newNum % 1000);
                }
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    finalResult[i][j] = tmpMat[i][j];
                }
            }
        }
    }
    
    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << finalResult[i][j] << ((j == n - 1) ? '\n' : ' ');
        }
    }
    
    return 0;
}
