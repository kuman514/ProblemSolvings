# Solving BOJ 20839

a, c, e = list(map(int, input().split()))
x, y, z = list(map(int, input().split()))

if x >= a and y >= c and z >= e:
    print('A')
elif x >= (a / 2) and y >= c and z >= e:
    print('B')
elif y >= c and z >= e:
    print('C')
elif y >= (c / 2) and z >= e:
    print('D')
elif z >= e:
    print('E')
