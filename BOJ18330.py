# Solving BOJ 18330

n = int(input())
m = int(input())

remain = 60 + m
result1 = 1500 * min(60 + m, n)
result2 = 3000 * max(0, n - 60 - m)
print(result1 + result2)
