#include <iostream>

// Solving BOJ 16968

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    char rule[5] = {'\0',};
    std::cin >> rule;
    
    int result = 1;
    int combo = 0;
    char current = 'a';
    
    for(int i = 0; rule[i] != '\0'; i++)
    {
        if(current != rule[i])
        {
            current = rule[i];
            combo = 0;
        }
        
        switch(rule[i])
        {
            case 'c':
                result *= (26 - (combo > 0 ? 1 : 0));
                break;
            case 'd':
                result *= (10 - (combo > 0 ? 1 : 0));
                break;
        }
        
        combo++;
    }
    
    std::cout << result << '\n';

    return 0;
}
