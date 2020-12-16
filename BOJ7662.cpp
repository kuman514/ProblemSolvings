#include <iostream>
#include <set>
#include <algorithm>

// solving BOJ 7662

void DoubleQueue()
{
    std::multiset<int> contain;
    
    int n;
    std::cin >> n;
    
    char command;
    int num;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> command >> num;
        
        switch(command)
        {
            case 'I':
                contain.insert(num);
                break;
                
            case 'D':
                if(contain.empty())
                {
                    break;
                }
                if(num == 1)
                {
                    std::multiset<int>::iterator tmp = contain.end();
                    tmp--;
                    
                    //std::cout << "Deleting " << *tmp << '\n';
                    contain.erase(tmp);
                }
                else if(num == -1)
                {
                    std::multiset<int>::iterator tmp = contain.begin();
                    
                    //std::cout << "Deleting " << *tmp << '\n';
                    contain.erase(tmp);
                }
                break;
        }
    }
    
    if(contain.empty())
    {
        std::cout << "EMPTY\n";
    }
    else
    {
        std::cout << (*contain.rbegin()) << ' ' << (*contain.begin()) << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int testcase;
    std::cin >> testcase;
    
    for(int T = 0; T < testcase; T++)
    {
        DoubleQueue();
    }
    
    return 0;
}
