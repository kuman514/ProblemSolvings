# Solving BOJ 19134


def getMaximumValue(n):
    result = 0
    s = n
    t = (n - 2) // 2 if n >= 2 else 0
    
    while s > 0:
        result += (s - t)
        s = (t - 2) // 2 if t >= 2 else 0
        t = (s - 2) // 2 if s >= 2 else 0
    
    return result


if __name__ == '__main__':
    num = int(input())
    print(getMaximumValue(num))
