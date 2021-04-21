import math 

N = int(input())
A = list(map(int,input().split()))
B, C = map(int, input().split())
answer = N
for a in A:
    R = a - B
    if R>0:
        if R % C:
            answer += (R // C) + 1
        else :
            answer += (R // C)

print(answer)

