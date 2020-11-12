#include <iostream>
#include <cstdio>
#include <cmath>

// Solving BOJ 2042

long long initTree(long long *arr, long long *tree, int nodenum, int start, int end)
{
    if(start == end) tree[nodenum] = arr[start];
    else tree[nodenum] = initTree(arr, tree, 2 * nodenum, start, (start+end) / 2)
                         + initTree(arr, tree, 2 * nodenum + 1, (start + end) / 2 + 1, end);
    
    return tree[nodenum];
}

long long getAreaSum(long long *tree, int nodenum, int start, int end, int arealeft, int arearight)
{
    if(arealeft > end || arearight < start) return 0;
    else if(arealeft <= start && end <= arearight) return tree[nodenum];
    else return getAreaSum(tree, 2 * nodenum, start, (start + end) / 2, arealeft, arearight)
                + getAreaSum(tree, 2 * nodenum + 1, (start + end) / 2 + 1, end, arealeft, arearight);
}

void updateTree(long long *tree, int nodenum, int start, int end, int index, long long diff)
{
    if(index < start || index > end) return;
    else
    {
        tree[nodenum] += diff;
        if(start != end)
        {
            updateTree(tree, 2 * nodenum, start, (start + end) / 2, index, diff);
            updateTree(tree, 2 * nodenum + 1, (start + end) / 2 + 1, end, index, diff);
        }
    }
}

int main(void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    long long array[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &array[i]);
    }
    
    long long tree[(int)pow(2, (int)ceil(log2(N)) + 1) - 1];
    initTree(array, tree, 1, 0, N - 1);
    
    int a, b, c;
    long long d;
    for(int i = 0; i < M + K; i++)
    {
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                scanf("%d %lld", &b, &d);
                updateTree(tree, 1, 0, N - 1, b - 1, d-array[b - 1]);
                array[b - 1] = d;
                break;
            case 2:
                scanf("%d %d", &b, &c);
                printf("%lld\n", getAreaSum(tree, 1, 0, N - 1, b - 1, c - 1));
                break;
        }
    }
    
    return 0;
}
