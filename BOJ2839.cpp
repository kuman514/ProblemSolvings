#include <cstdio>

// solving BOJ 2839

int main(void)
{
    int kg = 0, three = 0, five = 0, least = -1;
    scanf("%d", &kg);
    
    for(three = 0; three * 3 <= kg; three++)
    {
        if((five = (kg - (three * 3))) % 5 == 0)
        {
            five /= 5;
            if(least == -1 || (three + five) < least)
            {
                least = three + five;
            }
        }
    }
    
    printf("%d\n", least);
    return 0;
}
