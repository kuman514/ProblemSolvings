# Solving BOJ 1002

import math

def main():
    N = int(input())
    result = []
    for i in range(0,N):
        x1,y1,r1,x2,y2,r2 = tuple(map(int,input().split()))
        if x1 == x2 and y1 == y2 and r1 == r2:
            result.append(-1)
        else:
            betwn = math.sqrt((x1-x2)**2 + (y1-y2)**2)
            if betwn < r1+r2:
                shorter = betwn+min(r1,r2)
                longer = max(r1,r2)
                if shorter == longer:
                    result.append(1)
                elif shorter > longer:
                    result.append(2)
                else:
                    result.append(0)
            elif betwn == r1+r2:
                result.append(1)
            else:
                result.append(0)
    for i in range(0,N):
        print(result[i])
        

if __name__ == '__main__':
    main()
