# Solving BOJ 24294

w1 = int(input())
h1 = int(input())
w2 = int(input())
h2 = int(input())

w = max(w1, w2)
h = h1 + h2

print(2 * (w + h) + 4)
