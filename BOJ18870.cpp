#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// solving BOJ 18870

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::map< int, std::vector<int> > correspond;
    std::vector<int> contain;
    
    for(int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        
        std::map< int, std::vector<int> >::iterator it = correspond.find(input);
        
        if(it != correspond.end())
        {
            it -> second.push_back(i);
        }
        else
        {
            correspond.insert(std::pair< int, std::vector<int> >(input, std::vector<int>()));
            correspond[input].push_back(i);
            
            contain.push_back(input);
        }
    }
    
    std::sort(contain.begin(), contain.end());
    
    std::vector<int> result(n, 0);
    for(int i = 0; i < contain.size(); i++)
    {
        std::vector<int>& checkup = correspond[contain[i]];
        for(int j = 0; j < checkup.size(); j++)
        {
            result[checkup[j]] = i;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
