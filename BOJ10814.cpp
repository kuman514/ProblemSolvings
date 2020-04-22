#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

// solving BOJ 10814

bool mySort(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
{
    if(b.first > a.first)
    {
        return true;
    }
    
    return false;
}

int main(void)
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    // first: age of an employee, second: name of an employee
    std::pair<int, std::string> members[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> members[i].first >> members[i].second;
    }
    
    // Difference between std::sort and std::stable_sort
    // std::stable_sort guarantees the order of elements if they have same values
    std::stable_sort(members, members + n, mySort);
    
    for(int i = 0; i < n; i++)
    {
        std::cout << members[i].first << ' ' << members[i].second << '\n';
    }
    
    return 0;
}
