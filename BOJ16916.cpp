#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

// Solving BOJ 16916

int fail[1000001];

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
    
    std::string s, p;
    getline(std::cin, s);
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
    
    bool sget = FindWithKMP(s, p);
    
    // Print result
    std::cout << (sget ? 1 : 0) << '\n';
    
    return 0;
}
