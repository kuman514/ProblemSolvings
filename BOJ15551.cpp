#include <iostream>
#include <cstdio>

// solving BOJ 15551

int main(void)
{
    // Java String Hashcode Value
    // = Σ(str[i] * 31 ^ (n - 1 - i))
    // where i is an integer, ranges 0 <= i < n, str is a string
    // str[i] == ASCII value of a char, n == length of str
    
    // These 2 strings have a same Hashcode value
    const char *a = "aX", *b = "b9";
    
    int n;
    scanf("%d", &n);
    const int limit = n - 2;
    
    // Therefore, "+++...+++aX" and "+++...+++b9" also will have a same Hashcode value
    for(int i = 0; i < limit; i++)
        putchar('+');
    printf("%s\n", a);
    
    for(int i = 0; i < limit; i++)
        putchar('+');
    printf("%s\n", b);
    
    return 0;
}
