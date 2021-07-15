n, m = map(int, input().split())

result = 0
for i in range(n):
    data = list(map(int, input().split()))
    min_value = min(data)

    result = max(min_value, result)

# 입력 받을 때 마다 각 행에서 가장 낮은 수를 가져옴
# 다음 행으로 넘어갈 때 비교하는 행과 비교하여 높은 수를 저장
# 각 행에서의 가장 낮은 값들을 비교하여 가장 높은 수를 result로 리턴
    
print(result)
