#include <iostream>
#include <string>

// Solving BOJ 1343

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string board;
    std::cin >> board;
    
    int start = -1;
    for(int i = 0; i < board.length(); i++)
    {
        start = i;
        
        if(board[start] == '.')
        {
            continue;
        }
        
        i++;
        while(i - start < 4 && i < board.length())
        {
            if(board[i] == '.')
            {
                break;
            }
            
            i++;
        }
        
        char result = 'X';
        if(i - start == 2)
        {
            result = 'B';
        }
        else if(i - start == 4)
        {
            result = 'A';
        }
        else
        {
            std::cout << "-1\n";
            return 0;
        }
        
        for(int j = start; j < i; j++)
        {
            board[j] = result;
        }
        
        i--;
    }

    std::cout << board << '\n';
    return 0;
}
