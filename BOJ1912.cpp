#include <iostream>
#include <vector>

// Solving BOJ 1912

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<int> arr;
    
    int input;
    for(int i = 0; i < n; i++)
    {
        std::cin >> input;
        arr.push_back(input);
    }
    
    // it's promising if the previous memoization is larger than 0
    for(int i = 1; i < n; i++)
    {
        if(arr[i - 1] > 0)
        {
            arr[i] += arr[i - 1];
        }
    }
    
    int highest = -1000 * 100000 - 1;
    for(int i = 0; i < n; i++)
    {
        if(highest < arr[i])
        {
            highest = arr[i];
        }
    }
    
    std::cout << highest << '\n';
    
    return 0;
}
