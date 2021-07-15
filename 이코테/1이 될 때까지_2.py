N, K = map(int, input().split())

result = 0

while N >= K:
    # N이 K로 나누어 질 때, 나머지가 0이 아니면
    # N에 1빼는 1번 수행
    # count(result)를 1 증가시킴
    while N % K != 0:
        N -= 1
        result += 1
    # N이 K로 나누어지게 될 경우, N을 K로 나누고 
    # count(result)를 1 증가시킴 
    N //= K
    result += 1

# N이 K보다 작아서 나눌 수 없는 수를 
# count(result) 적용시킴
while N>1:
    N -= 1
    result += 1

print(result)
