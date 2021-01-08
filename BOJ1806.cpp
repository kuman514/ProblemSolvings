#include <iostream>
#include <vector>

// Solving BOJ 1806

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n, limit;
    std::cin >> n >> limit;
    
    std::vector<int> arr(n, 0);
    int initsum = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        initsum += arr[i];
    }
    
    if(initsum < limit)
    {
        std::cout << "0\n";
    }
    else
    {
        // Calculate using Two Pointer Algorithm
        // sum = SUM up arr[start, end)
        
        int sum = 0;
        int start = 0;
        int end = 0;
        int length = n;
        
        while(start < n)
        {
            if(sum > limit || end >= n)
            {
                sum -= arr[start];
                start++;
            }
            else
            {
                sum += arr[end];
                end++;
            }
            
            if(sum >= limit && length > end - start)
            {
                length = end - start;
            }
        }
        
        std::cout << length << '\n';
    }
    
    return 0;
}
