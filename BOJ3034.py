# Solving BOJ 3034

n, w, h = list(map(int, input().split()))
i = 0
while i < n:
    l = int(input())
    if l <= w or l <= h or (l * l) <= (w * w) + (h * h):
        print('DA')
    else:
        print('NE')
    i += 1
