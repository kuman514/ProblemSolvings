#include <iostream>
#include <vector>

// Solving BOJ 1991

const char leaf = '.';
const int PREFIX = 1;
const int INFIX = 2;
const int POSTFIX = 3;

void Travel(std::vector< std::pair<char, char> > &tree, char name, int method)
{
    int index = name - 'A';
    
    // Prefix Process
    if(method == PREFIX)
    {
        std::cout << name;
    }
    
    // Left Child
    if(tree[index].first != leaf)
    {
        Travel(tree, tree[index].first, method);
    }
    
    // Infix Process
    if(method == INFIX)
    {
        std::cout << name;
    }
    
    // Right Child
    if(tree[index].second != leaf)
    {
        Travel(tree, tree[index].second, method);
    }
    
    // Postfix Process
    if(method == POSTFIX)
    {
        std::cout << name;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    // Get input
    std::vector< std::pair<char, char> > tree(n, {'\0', '\0'});
    for(int i = 0; i < n; i++)
    {
        char input;
        std::cin >> input;
        
        int index = input - 'A';
        
        std::cin >> tree[index].first;
        std::cin >> tree[index].second;
    }
    
    // Prefix
    Travel(tree, 'A', PREFIX);
    std::cout << '\n';
    
    // Infix
    Travel(tree, 'A', INFIX);
    std::cout << '\n';
    
    // Postfix
    Travel(tree, 'A', POSTFIX);
    std::cout << '\n';

    return 0;
}
