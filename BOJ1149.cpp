#include <iostream>
#include <vector>

// solving BOJ 1149

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // 0: red, 1: green, 2: blue
    std::vector< std::vector<int> > house(n, std::vector<int>(3, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> house[i][j];
        }
    }
    
    std::vector<int> result(3, 0);
    result[0] = house[0][0];
    result[1] = house[0][1];
    result[2] = house[0][2];
    //std::cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
    
    for(int i = 1; i < n; i++)
    {
        int tmp[3] = {0,};
        
        tmp[0] = house[i][0] + std::min(result[1], result[2]);
        tmp[1] = house[i][1] + std::min(result[0], result[2]);
        tmp[2] = house[i][2] + std::min(result[0], result[1]);
        
        result[0] = tmp[0];
        result[1] = tmp[1];
        result[2] = tmp[2];
        
        //std::cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
    }
    
    int minimum = 10000001;
    for(int i = 0; i < 3; i++)
    {
        if(minimum > result[i])
        {
            minimum = result[i];
        }
    }
    
    std::cout << minimum << '\n';

    return 0;
}
