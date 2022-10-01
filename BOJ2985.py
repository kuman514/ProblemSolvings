# Solving BOJ 2985

a, b, c = list(map(int, input().split()))

if a == b + c:
    print('%d=%d+%d' % (a, b, c))
elif a == b - c:
    print('%d=%d-%d' % (a, b, c))
elif a == b * c:
    print('%d=%d*%d' % (a, b, c))
elif a == b // c:
    print('%d=%d/%d' % (a, b, c))
elif a + b == c:
    print('%d+%d=%d' % (a, b, c))
elif a - b == c:
    print('%d-%d=%d' % (a, b, c))
elif a * b == c:
    print('%d*%d=%d' % (a, b, c))
elif a // b == c:
    print('%d/%d=%d' % (a, b, c))
elif a == b and b == c:
    print('%d=%d=%d' % (a, b, c))
