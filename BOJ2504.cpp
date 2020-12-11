#include <iostream>
#include <cstdio>
#include <stack>

// Solving BOJ 2504

int main(void)
{
    char input[31];
    scanf("%s", input);
    
    int result = 0, depthtotal[30] = {0,}, depth;
    std::stack<char> bstack;
    
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == '(' || input[i] == '[')
        {
            bstack.push(input[i]);
        }
        else if(input[i] == ')')
        {
            if(bstack.empty() || bstack.top() == '[')
            {
                result = 0;
                break;
            }
            else
            {
                bstack.pop();
                depth = bstack.size();
                
                if(depthtotal[depth + 1] == 0)
                {
                    depthtotal[depth] += 2;
                }
                else 
                {
                    depthtotal[depth] += (2 * depthtotal[depth + 1]);
                    depthtotal[depth + 1] = 0;
                }
            }
        }
        else if(input[i] == ']')
        {
            if(bstack.empty() || bstack.top() == '(')
            {
                result = 0;
                break;
            }
            else
            {
                bstack.pop();
                depth = bstack.size();
                
                if(depthtotal[depth + 1] == 0)
                {
                    depthtotal[depth] += 3;
                }
                else 
                {
                    depthtotal[depth] += (3 * depthtotal[depth + 1]);
                    depthtotal[depth + 1] = 0;
                }
            }
        }
        
        result = depthtotal[0];
    }
    
    printf("%d\n", result);
    
    return 0;
}
