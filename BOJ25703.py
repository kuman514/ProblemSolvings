# Solving BOJ 25703

n = int(input())
i = 0
while i <= n:
    if i == 0:
        print('int a;')
    elif i == 1:
        print('int *ptr = &a;')
    elif i == 2:
        print('int **ptr2 = &ptr;')
    else:
        print('int %sptr%d = &ptr%d;' % ('*' * i, i, i - 1))
    i += 1
