n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

# ex) 5 3 8 \n 2 4 5 4 6
# first = 6
# second = 5
# [6 6 6 5][6 6 6 5]
# = 2*(6 * 3) + (8%4)*6 + 2*(5)
# = ((k//(m+1))*k)*first + (k%(m+1))*first + (k//(m+1))*second
# = (((k//(m+1))*k) + (k%(m+1)))* first + (k//(m+1))*second

count = int(m/ (k+1)) * k
count += m % (k+1)

result = 0
result += (count)* first
result += (m-count) * second # first를 제외한 개수를 second로 채움

print(result)

# 수열을 이용한 효율적인 
