#include <iostream>
#include <vector>
#include <set>
#include <queue>

// Solving BOJ 1005

struct Build {
    int timeToBuild;
    std::set<int> requires;
    std::vector<int> unlocks;
    int startsAt;
};

struct Progress {
    int buildNum;
    int completesAt;
};

void playAcmCraft() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Get the number of buildings and rules
    int n, k;
    std::cin >> n >> k;
    
    // Initialize buildings
    std::vector<Build> buildings(n, {
        0,
        std::set<int>(),
        std::vector<int>(),
        0
    });
    
    // Get the time to build each building
    for (int i = 0; i < n; i++) {
        std::cin >> buildings[i].timeToBuild;
    }
    
    // Get the buildings' requirements
    for (int i = 0; i < k; i++) {
        int require, unlock;
        std::cin >> require >> unlock;
        
        require--;
        unlock--;
        
        buildings[require].unlocks.push_back(unlock);
        buildings[unlock].requires.insert(require);
    }
    
    // Get the target building
    int target;
    std::cin >> target;
    target--;
    
    // Start from buildings with no requirements
    std::queue<Progress> inProgress;
    for (int i = 0; i < n; i++) {
        if (buildings[i].requires.size() == 0) {
            inProgress.push({
                i, buildings[i].timeToBuild
            });
        }
    }
    
    // Process building
    while (!inProgress.empty()) {
        Progress currentBuild = inProgress.front();
        inProgress.pop();
        
        // Is target?
        if (currentBuild.buildNum == target) {
            std::cout << currentBuild.completesAt << '\n';
            return;
        }
        
        // Process these children
        for (int i = 0; i < buildings[currentBuild.buildNum].unlocks.size(); i++) {
            int unlockBuildNum = buildings[currentBuild.buildNum].unlocks[i];
            
            // Unlock the buildings
            buildings[unlockBuildNum].requires.erase(currentBuild.buildNum);
            
            // Update the child building's startsAt
            if (buildings[unlockBuildNum].startsAt < currentBuild.completesAt) {
                buildings[unlockBuildNum].startsAt = currentBuild.completesAt;
            }
            
            // If no more requirements, push to queue
            if (buildings[unlockBuildNum].requires.size() == 0) {
                inProgress.push({
                    unlockBuildNum,
                    buildings[unlockBuildNum].startsAt + buildings[unlockBuildNum].timeToBuild
                });
            }
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        playAcmCraft();
    }

    return 0;
}
