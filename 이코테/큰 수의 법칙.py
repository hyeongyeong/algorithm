# 문제 :
# n 크기의 array
# array 안의 숫자에서 숫자들을 총 m번 사용하여 최대합 구하기
# 단, array 안의 숫자들은 중복 가능하며 최대 k번 중복 허용

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort(reverse=True)
first = data[0]
second = data[1]
sum = 0
count = 0
for i in range(m):
    if(count >= k):
        count = 0
        sum += second
    else :
        sum += first
        count +=1
print(sum)
