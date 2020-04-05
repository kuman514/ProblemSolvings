#include <iostream>
#include <cstdio>

// solving BOJ 1316

int main(void)
{
    int N;
    scanf("%d", &N);
    
    char word[101];
    int count = 0;
    
    for(int i = 0; i < N; i++)
    {
        bool check[26] = { (bool)0, };
        bool fail = false;
        
        // get input
        scanf("%s", word);
        
        for(int k = 0; word[k] != '\0'; k++)
        {
            if(!check[(int)(word[k] - 'a')])
            {
                // if current alphabet is not duplicated
                // skip until another alphabet is found
                
                while(word[k+1] == word[k])
                {
                    k++;
                }
                
                // duplication-not-allowed flag
                check[(int)(word[k] - 'a')] = true;
            }
            else
            {
                // if current alphabet is duplicated
                // the word failed to be a group word
                
                fail = true;
                break;
            }
        }
        
        // if it is a group word
        if(!fail) count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
