#include <iostream>
#include <cstring>

// solving BOJ 9324

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int testcase;
    std::cin >> testcase;
    
    char input[100001];
    for(int i = 0; i < testcase; i++)
    {
        std::cin >> input;
        
        bool fake = false;
        int length = strlen(input);
        int count[26] = {0,};
        
        for(int j = 0; j < length; j++)
        {
            count[input[j] - 'A']++;
            
            if(count[input[j] - 'A'] % 3 == 0)
            {
                fake = (input[j] != input[j + 1]);
                
                if(!fake)
                {
                    j++;
                }
            }
            
            if(fake)
            {
                break;
            }
        }
        
        if(fake)
        {
            std::cout << "FAKE" << '\n';
        }
        else
        {
            std::cout << "OK" << '\n';
        }
    }

    return 0;
}
