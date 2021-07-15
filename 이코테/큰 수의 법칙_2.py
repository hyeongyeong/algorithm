n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

result = 0

while True:
    for i in range(k):
        if m == 0 :
            break
        result += first
        m -= 1

    if m == 0:
        break
    result += second
    m -= 1

print(result)

# 총 m번을 하므로 한번 result에 더할 때마다 m = m-1
# 가장 큰 값을 최대 k번까지 더할 수 있으므로 k번 first 값을 result에 더함
# k번 이상이 되었을 때 loop를 빠져나와 두 번째 큰 값을 더한 후 다시 가장 큰 값을 더하기
