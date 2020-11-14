#include <iostream>
#include <cmath>

// Solving BOJ 1107

bool BrokenButtonDoesNotMatter(int target, bool* broken)
{
    do
    {
        if(broken[target % 10])
        {
            return false;
        }
        
        target /= 10;
    }
    while(target > 0);
    
    return true;
}

int GetUpper(int target, bool* broken)
{
    int current = target;
    
    while(current < 1000000)
    {
        if(BrokenButtonDoesNotMatter(current, broken))
        {
            break;
        }
        
        current++;
    }
    
    if(current < 0) return 2147483647;
    else return current;
}

int GetLower(int target, bool* broken)
{
    int current = target;
    
    while(current >= 0)
    {
        if(BrokenButtonDoesNotMatter(current, broken))
        {
            break;
        }
        
        current--;
    }
    
    if(current < 0) return -2147483647;
    else return current;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int target, buttons;
    bool malfunc[10] = {false,};
    
    // Get input
    std::cin >> target;
    std::cin >> buttons;
    for(int i = 0; i < buttons; i++)
    {
        int input;
        std::cin >> input;
        malfunc[input] = true;
    }
    
    // Calculate and show result
    int usingOnlyUpOrDown = std::abs(target - 100);
    bool brokenDontMatter = BrokenButtonDoesNotMatter(target, malfunc);
    
    if(buttons == 0 || brokenDontMatter)
    {
        // If all buttons work or broken buttons don't matter
        int digits = 0;
        if(target == 0)
        {
            digits = 1;
        }
        else
        {
            digits = static_cast<int>(std::log10(target) + 1);
        }
        
        std::cout << std::min(digits, usingOnlyUpOrDown) << '\n';
    }
    else if(buttons == 10)
    {
        // If no button works
        std::cout << usingOnlyUpOrDown << '\n';
    }
    else
    {
        int up = GetUpper(target, malfunc);
        int down = GetLower(target, malfunc);
        
        int updigits = 0;
        if(up == 0)
        {
            updigits = 1;
        }
        else
        {
            updigits = static_cast<int>(std::log10(up) + 1);
        }
        
        int downdigits = 0;
        if(down == 0)
        {
            downdigits = 1;
        }
        else
        {
            downdigits = static_cast<int>(std::log10(down) + 1);
        }
        
        if(down < 0)
        {
            std::cout << std::min(updigits + std::abs(up - target), usingOnlyUpOrDown) << '\n';
        }
        else
        {
            int upper = updigits + std::abs(up - target);
            int lower = downdigits + std::abs(down - target);
            int candidate = std::min(upper, lower);
            
            std::cout << std::min(candidate, usingOnlyUpOrDown) << '\n';
        }
    }

    return 0;
}
