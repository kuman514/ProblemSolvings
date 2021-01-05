#include <iostream>
#include <vector>
#include <string>
#include <map>

// Solving BOJ 9375

void WearCombination(void)
{
    int n;
    std::cin >> n;
    std::map<std::string, int> items;
    
    // Get input
    for(int i = 0; i < n; i++)
    {
        std::string name;
        std::string type;
        
        std::cin >> name >> type;
        if(items.find(type) == items.end())
        {
            items.insert(std::pair<std::string, int>(type, 0));
        }
        
        items[type]++;
    }
    
    // Calculate total combinations
    int total = 1;
    for(std::map<std::string, int>::iterator it = items.begin(); it != items.end(); ++it)
    {
        total *= ((it -> second) + 1);
    }
    
    total--;
    
    std::cout << total << '\n';
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int testcase;
    std::cin >> testcase;
    
    for(int i = 0; i < testcase; i++)
    {
        WearCombination();
    }
    
    return 0;
}
