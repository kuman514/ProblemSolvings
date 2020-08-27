# Solving BOJ 2003 using Python3


def twopointsolve(arr, target):
    i, j = 0, 0
    count = 0

    tmpsum = 0
    while i < len(arr):
        if tmpsum >= target:
            count += 1 if tmpsum == target else 0
            i += 1
            tmpsum -= arr[i-1]
        else:
            if j == len(arr):
                i += 1
                tmpsum -= arr[i-1]
            else:
                j += 1
                tmpsum += arr[j-1]
            
    
    return count


if __name__ == '__main__':
    num, tar = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(twopointsolve(arr, tar))
