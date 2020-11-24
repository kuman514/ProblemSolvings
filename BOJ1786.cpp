#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

// Solving BOJ 1786

int main()
{
    // Get input
    std::string t, p;
    getline(std::cin, t);
    getline(std::cin, p);
    
    int tlen = t.length(), plen = p.length();
    
    // Calculate fail values
    int fail[1000000] = {0,};
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
    
    // Find match pattern using KMP
    std::vector<int> foundIndex;
    int j = 0;
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
                foundIndex.push_back((i - plen + 1) + 1);
                j = fail[j];
            }
            else
            {
                j++;
            }
        }
    }
    
    // Print result
    printf("%d\n", static_cast<int>(foundIndex.size()));
    for(std::vector<int>::iterator it = foundIndex.begin(); it != foundIndex.end(); it++)
    {
        printf("%d\n", *it);
    }
    
    return 0;
}
