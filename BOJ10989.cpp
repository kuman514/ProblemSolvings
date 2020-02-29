#include <iostream>
#include <cstdio>

// solving BOJ 10989

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    // each number is no more than 10000
    short input;
    
    // using short counter due to memory constraints
    short result[10001] = {0,};
    
    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        result[input]++;
    }
    
    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 0; j < result[i]; j++)
        {
            std::cout << i << '\n';
        }
    }
    
    return 0;
}
