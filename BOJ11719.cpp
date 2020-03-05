#include <iostream>
#include <cstdio>

// solving BOJ 11719

int main(void)
{ 
    char input[101];
    
    // char* gets(char *str)
    // get string input and copy it to str
    // if '\n' appears, the string ends right before '\n', copies the string and '\0' right after it to str, and returns the address of str
    // if EOF appears, just returns null pointer, and keeps str unchanged
    
    while(gets(input))
    {
        puts(input);
    }
    
    return 0;
}