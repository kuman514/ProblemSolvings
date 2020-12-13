#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

// Solving BOJ 2108

struct counter
{
    int num;
    int count;
    counter(int N = 0) : num(N), count(0) {}
};

bool ccmp(counter L, counter R)
{
    if(L.count > R.count) return true;
    else if(L.count == R.count && L.num < R.num) return true;
    else return false;
}

int convert(double n)
{
    if(n < 0)
    {
        if(n - (int)n <= -0.5) return (int)(n - 1);
        else return (int)n;
    }
    else
    {
        if(n - (int)n >= 0.5) return (int)(n + 1);
        else return (int)n;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int num[N];
    int sum = 0, max = -4001, min = 4001;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
        
        if(num[i] > max) max = num[i];
        if(num[i] < min) min = num[i];
    }
    
    std::sort(num, num + N);
    
    double avg = (double)sum / N;
    int center = num[N / 2];
    int range = max - min;
    
    counter many[N];
    int x = 0;
    for(int i = 0; i < N; i++)
    {
        if(i > 0 && num[i - 1] == num[i])
        {
            x--;
            many[x].count++;
        }
        else
        {
            many[x].num = num[i];
            many[x].count++;
        }
        
        x++;
    }
    
    std::sort(many, many + x, ccmp);
    
    int freq = (many[0].count == many[1].count) ? many[1].num : many[0].num;
    
    printf("%d\n", convert(avg));
    printf("%d\n", center);
    printf("%d\n", freq);
    printf("%d\n", range);
    
    return 0;
}
