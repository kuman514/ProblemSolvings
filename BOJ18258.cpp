#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

// Solving BOJ 18258

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::queue<int> q;
    int n;
    std::cin >> n;
    
    std::string command;
    command.reserve(6);
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> command;
        
        if(command == "push")
        {
            int element;
            std::cin >> element;
            q.push(element);
        }
        else if(command == "pop")
        {
            if(q.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(command == "size")
        {
            std::cout << q.size() << '\n';
        }
        else if(command == "empty")
        {
            std::cout << q.empty() << '\n';
        }
        else if(command == "front")
        {
            std::cout << (q.empty() ? -1 : q.front()) << '\n';
        }
        else if(command == "back")
        {
            std::cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }
    
    return 0;
}
