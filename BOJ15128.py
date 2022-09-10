# Solving BOJ 15128

p1, q1, p2, q2 = list(map(int, input().split()))
p = p1 * p2
q = q1 * q2
if p % (q * 2) == 0:
    print(1)
else:
    print(0)
