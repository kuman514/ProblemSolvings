#include <iostream>
#include <vector>
#include <set>
#include <queue>

// Solving BOJ 1766

struct Problem {
    std::set<int> requires;
    std::vector<int> unlocks;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get the number of problems and rules
    int n, k;
    std::cin >> n >> k;
    
    // Initialize problems
    std::vector<Problem> problems(n, {
        std::set<int>(),
        std::vector<int>()
    });
    
    // Get the problems' requirements
    for (int i = 0; i < k; i++) {
        int require, unlock;
        std::cin >> require >> unlock;
        
        require--;
        unlock--;
        
        problems[require].unlocks.push_back(unlock);
        problems[unlock].requires.insert(require);
    }
    
    // Declare vector for sequence
    std::vector<int> sequence;
    
    // Get problems with no requirements
    std::priority_queue< int, std::vector<int>, std::greater<int> > inProgress;
    for (int i = 0; i < n; i++) {
        if (problems[i].requires.size() == 0) {
            inProgress.push(i);
        }
    }
    
    // Process building
    while (!inProgress.empty()) {
        int currentProblem = inProgress.top();
        inProgress.pop();
        
        // Solve this problem
        sequence.push_back(currentProblem + 1);
        
        // Process these children
        for (int i = 0; i < problems[currentProblem].unlocks.size(); i++) {
            int unlockBuildNum = problems[currentProblem].unlocks[i];
            
            // Unlock the problems
            problems[unlockBuildNum].requires.erase(currentProblem);
            
            // If no more requirements, push to queue
            if (problems[unlockBuildNum].requires.size() == 0) {
                inProgress.push(unlockBuildNum);
            }
        }
    }
    
    // Show result
    for (int i = 0; i < sequence.size(); i++) {
        if (i == sequence.size() - 1) {
            std::cout << sequence[i] << '\n';
        } else {
            std::cout << sequence[i] << ' ';
        }
    }

    return 0;
}
