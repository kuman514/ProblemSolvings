#include <iostream>
#include <cstdio>

// solving BOJ 14888

int n;                      // the number of operands
int num[11];                // an array that contains values of operands
int opers[4];               // the number of each operator

int min = 1000000001;       // minimum value
int max = -1000000001;      // maximum value

void calculate(int turn, const int val)
{
    for(int i = 0; i < 4; i++)
    {
        // if an operator can still be used, calculate the value
        // the method ignores Arithmetic Laws
        
        if(opers[i] > 0)
        {
            int curval;
            switch(i)
            {
                case 0:
                    curval = val + num[turn];
                    break;
                case 1:
                    curval = val - num[turn];
                    break;
                case 2:
                    curval = val * num[turn];
                    break;
                case 3:
                    curval = val / num[turn];
                    break;
            }
            
            if(turn < n-1)
            {
                // if it is not complete, step into the next level
                opers[i]--;
                calculate(turn + 1, curval);
                
                // restore
                opers[i]++;
            }
            else
            {
                // if completed, compare min/max values
                if(curval < min) min = curval;
                if(curval > max) max = curval;
            }
        }
    }
}

int main(void)
{
    // input the number of operands
    scanf("%d", &n);
    
    // input the value of each operand
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }
    
    // input the number of each operator
    for(int i=0; i<4; i++)
    {
        scanf("%d", &opers[i]);
    }
    
    // method starts
    calculate(1, num[0]);
    
    // printing result
    printf("%d\n%d\n", max, min);
    
    return 0;
}
