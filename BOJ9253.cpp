#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

// Solving BOJ 9253

int fail[200001];

bool FindWithKMP(std::string &t, std::string &p)
{
    // Find match pattern using KMP
    std::vector<int> foundIndex;
    int tlen = t.length(), plen = p.length(), j = 0;
    
    for(int i = 0; i < tlen; i++)
    {
        while(j > 0 && t[i] != p[j])
        {
            j = fail[j - 1];
        }
        
        if(t[i] == p[j])
        {
            if(j == plen - 1)
            {
                return true;
                
                /*
                foundIndex.push_back((i - plen + 1) + 1);
                j = fail[j];
                */
            }
            else
            {
                j++;
            }
        }
    }
    
    return false;
}

int main()
{
    // Get input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string t1, t2, p;
    getline(std::cin, t1);
    getline(std::cin, t2);
    getline(std::cin, p);
    
    int plen = p.length();
    
    // Calculate fail values
    for(int i = 1, j = 0; i < plen; i++)
    {
        while(j > 0 && p[i] != p[j])
        {
            j = fail[j - 1];
        }
        
        if(p[i] == p[j])
        {
            j++;
            fail[i] = j;
        }
    }
    
    bool t1get = FindWithKMP(t1, p);
    bool t2get = FindWithKMP(t2, p);
    
    // Print result
    if(t1get && t2get)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
    
    return 0;
}
