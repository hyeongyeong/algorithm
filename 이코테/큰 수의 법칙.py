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
