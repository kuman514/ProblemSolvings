#include <iostream>
#include <cstdio>
#include <stack>

// solving BOJ 10799

int max(int a, int b) { return (a > b) ? a : b; }

int main(void)
{
    char bracket[100010];
    scanf("%s", bracket);
    
    std::stack<char> bstack;
    long long total = 0;
    
    for(int i = 0; bracket[i] != '\0'; i++)
    {
        if(bracket[i] == '(')
        {
            // stack up a steel stick
            bstack.push('(');
        }
        else // if(bracket[i] == ')')
        {
            // shoot a laser
            bstack.pop();
            
            if(bracket[i - 1] == '(')
            {
                // if there are sticks stacked up
                // get the number of the completely cut out sticks
                total += bstack.size();
            }
            else // if(bracket[i-1] == ')')
            {
                // get another completely cut out stick
                total += 1;
            }
        }
    }
    
    printf("%lld\n", total);
    
    return 0;
}
