N, K = map(int, input().split())

result = N
count = 0
while True:
    if result == 1:
        break
    if result % K != 0 or result // K == 0:
        result -= 1
    else:
        result = result//K
    count += 1

print(count)
