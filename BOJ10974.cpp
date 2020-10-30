#include <iostream>
#include <vector>
#include <algorithm>

// solving BOJ 10974

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<int> arr;
    for(int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    
    do
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << arr[i] << ' ';
        }
        
        std::cout << '\n';
    }
    while(std::next_permutation(arr.begin(), arr.end()));
    
    return 0;
}
