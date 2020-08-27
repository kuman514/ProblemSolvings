# Solving BOJ 15829


def MyHash(string, r = 31, M = 1234567891):
    total = 0
    subtractor = ord('a') - 1
    for i in range(len(string)):
        total += (ord(string[i]) - subtractor) * pow(r, i) % M
    
    return total % M


if __name__ == '__main__':
    _ = int(input())
    print(MyHash(input()))
