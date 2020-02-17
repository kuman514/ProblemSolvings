#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

// solving BOJ 1022

int main(void)
{
    // input
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
    // picking the furthest input point as the radius
    int tmp[4] = {std::abs(r1), std::abs(c1), std::abs(r2), std::abs(c2)};
    std::sort(tmp, tmp + 4);
    const int radius = tmp[3];
    
    // set the center half the diameter
    // diameter = radius * 2
    const int center = radius;
    
    // making a matrix for visualization of the whirpool
    const int xlength = c2 - c1 + 1, ylength = r2 - r1 + 1;
    int whirpool[ylength][xlength];
    
    const int maxN = (2 * radius + 1) * (2 * radius + 1);
    int row = 0, edge = 2 * row + 1;
    
    // initialize the cursors
    int curX = center, curY = center;
    int xmov = 1, ymov = 0;
    
    // pivoting the points in center
    r1 += radius;
    c1 += radius;
    r2 += radius;
    c2 += radius;
    
    // the biggest number visualized
    // this variable will be used for the space to visualize each number
    int maxResult = 0;
    
    /*
        whirpool
    
    y/x -3 -2 -1  0  1  2  3
        --------------------
    -3 |37 36 35 34 33 32 31
    -2 |38 17 16 15 14 13 30
    -1 |39 18  5  4  3 12 29
     0 |40 19  6  1  2 11 28
     1 |41 20  7  8  9 10 27
     2 |42 21 22 23 24 25 26
     3 |43 44 45 46 47 48 49
     
    radius - the final edge's distance from the center
    row - an edge's distance from the center
    edge - the end of each whirpool cycle (length: 2 * row + 1)
    
    whirpool cycle sequence: up -> left -> down -> right -> row++ and up again -> ...
    
    */
    
    for(int n = 1; n <= maxN; n++)
    {
        // save the number in the visualization range
        if((c1 <= curX && curX <= c2) && (r1 <= curY && curY <= r2))
        {
            whirpool[curY - r1][curX - c1] = n;
            if(maxResult < n) maxResult = n;
        }
        
        // whirpool cycle
        if(ymov < 0)
        {
            ymov++;
            if(ymov < 0) curY--;
            else xmov = -edge;
        }
        
        if(xmov < 0)
        {
            xmov++;
            if(xmov < 0) curX--;
            else ymov = edge;
        }
        
        if(ymov > 0)
        {
            ymov--;
            if(ymov > 0) curY++;
            else xmov = edge;
        }
        
        if(xmov > 0)
        {
            xmov--;
            if(xmov > 0) curX++;
            else
            {
                // if cycle is done
                row++;
                edge = 2 * row + 1;
                
                curX++;
                ymov = -edge + 1;
            }
        }
    }
    
    
    // print the result
    const int space = log10(maxResult) + 1;
    for(int i=r1; i<=r2; i++)
    {
        for(int j=c1; j<=c2; j++)
        {
            printf("%*d ", space, whirpool[i - r1][j - c1]);
        }
        
        putchar('\n');
    }
    
    return 0;
}