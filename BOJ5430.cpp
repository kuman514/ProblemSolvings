#include <iostream>
#include <cstdio>
#include <deque>

// Solving BOJ 5430

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        // prepare the deque
        
        char p[100001];
        scanf("%s", p);
        
        int n;
        scanf("%d", &n);
        
        char flowaway;
        int input;
        
        scanf("%c", &flowaway);         // remove '\n'
        scanf("%c", &flowaway);         // remove '['
        if(n == 0) scanf("%c", &flowaway);
    
        std::deque<int> curdq;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &input);        // get a number
            curdq.push_back(input);
            scanf("%c", &flowaway);     // remove ',' or ']'
        }
    
        scanf("%c", &flowaway);         // remove '\n'
        
        
        
        // main operation
        bool error = false, rev = false;
        for(int k = 0; p[k] != '\0'; k++)
        {
            if(p[k] == 'R') rev = !rev;
            else if(p[k] == 'D')
            {
                if(curdq.empty())
                {
                    error = true;
                    break;
                }
                else
                {
                    rev ? curdq.pop_back() : curdq.pop_front();
                }
            }
        }
        
        if(error) printf("error\n");
        else
        {
            putchar('[');
            while(!curdq.empty())
            {
                if(!rev)
                {
                    printf("%d", curdq.front());
                    curdq.pop_front();
                }
                else
                {
                    printf("%d", curdq.back());
                    curdq.pop_back();
                }
                
                if(!curdq.empty()) putchar(',');
            }
            printf("]\n");
        }
    }
    
    return 0;
}
