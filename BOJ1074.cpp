#include <iostream>
#include <cstdio>
#include <cmath>

// Solving BOJ 1074

int main(void)
{
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    
    int result = 0;
    int dimension = n;
    
    while(dimension > 0)
    {
        int F = std::pow(2, 2 * (dimension - 1));
        int posID = std::pow(2, dimension - 1);
        
        //printf("dimension %d: row %d, column %d\n", dimension, r, c);
        
        if(r < posID && c < posID)
        {
            // result += 0;
        }
        else if(r < posID && c >= posID)
        {
            result += F;
            c -= posID;
        }
        else if(r >= posID && c < posID)
        {
            result += 2 * F;
            r -= posID;
        }
        else // if(r >= posID && c >= posID)
        {
            result += 3 * F;
            r -= posID;
            c -= posID;
        }
        
        dimension -= 1;
    }
    
    printf("%d\n", result);
    
    return 0;
}
