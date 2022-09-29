# Solving BOJ 1598

x, y = list(map(int, input().split()))
n, m = [x - 1, y - 1]
horizontal = abs(n // 4 - m // 4)
vertical = abs(n % 4 - m % 4)
print(horizontal + vertical)
