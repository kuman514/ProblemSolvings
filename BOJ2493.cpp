#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>

// Solving BOJ 2493

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int towerheight[N];
    std::stack< std::pair<int, int> > towerstack;
    
    for(int i = 0; i < N; i++)
        scanf("%d", &towerheight[i]);
    
    int i = N - 1;                      // Starts from right to left.
    std::pair<int,int> towerinfo;       // first: the source tower of laser, second: height of the tower
    int result[N] = {0,};               // Position of the tower that catches its laser
    
    while(i >= 0)
    {
        if(!towerstack.empty())
        {
            towerinfo = towerstack.top();
            
            // Get all the lasers from towers behind
            while(!towerstack.empty() && towerinfo.second <= towerheight[i])
            {
                towerstack.pop();
                
                // If it's not higher than the current tower,
                // Record the current tower received the laser
                result[towerinfo.first] = i + 1;
                if(towerstack.empty()) break;
                
                towerinfo = towerstack.top();
            }
        }
        
        // Shoot laser to the next towers
        towerstack.push(std::pair<int,int>(i, towerheight[i]));
        i--;
    }
    
    for(int i=0; i<N; i++)
        printf("%d ", result[i]);
    putchar('\n');
    
    return 0;
}
