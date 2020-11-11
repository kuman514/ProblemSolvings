#include <iostream>
#include <cstdio>
#include <queue>

// Solving BOJ 1655

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    
    int input;
    std::priority_queue< int, std::vector<int>, std::less<int> > left;
    std::priority_queue< int, std::vector<int>, std::greater<int> > right;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> input;
        
        if(i == 0) left.push(input);
        else if(left.size() == right.size())
        {
            if(left.top() > input)
                left.push(input);
            else
            {
                if(right.top() < input)
                {
                    int temp = right.top();
                    right.pop();
                    right.push(input);
                    left.push(temp);
                }
                else
                    left.push(input);
            }
        }
        else if(left.size() > right.size())
        {
            if(left.top() > input)
            {
                int temp = left.top();
                left.pop();
                left.push(input);
                right.push(temp);
            }
            else
                right.push(input);
        }
        
        std::cout << left.top() << '\n';
    }
    
    return 0;
}
