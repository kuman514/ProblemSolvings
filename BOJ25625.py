# Solving BOJ 25625

x, y = list(map(int, input().split()))
if x <= y:
    print(y - x)
else:
    print(x + y)
