#include <iostream>
#include <vector>

// solving BOJ 1629

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b, c;
    std::cin >> a >> b >> c;
    
    long long mods[32] = {0,};
    mods[0] = a % c;
    for(int i = 1; i < 32; i++)
    {
        mods[i] = (mods[i - 1] * mods[i - 1]) % c;
    }
    
    bool flag[32] = {false,};
    int tmp = b;
    int limit = 0;
    while(tmp > 0)
    {
        if(tmp % 2 == 1)
        {
            flag[limit] = true;
        }
        
        limit++;
        tmp /= 2;
    }
    
    long long result = 1;
    for(int i = 0; i < limit; i++)
    {
        if(flag[i])
        {
            result = (result * mods[i]) % c;
        }
    }
    
    std::cout << result << '\n';

    return 0;
}
