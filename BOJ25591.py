# Solving BOJ 25591

x, y = list(map(int, input().split()))
a = 100 - x
b = 100 - y
c = 100 - (a + b)
d = a * b
q = d // 100
r = d % 100
print('%d %d %d %d %d %d' % (a, b, c, d, q, r))
if d < 100:
    print('%d %d' % (c, d))
else:
    print('%d %d' % (c + q, r))
