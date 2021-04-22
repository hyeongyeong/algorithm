
## input
N, M, x, y, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
commands = list(map(int, input().split()))

# direction
# 좌 우 상 하
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]

# init cube position
x = 0
y = 0

cube = 0

def getTop(bot):
    if bot: 
        return 6 - (bot-1)
    else: return 0

def check_boundary(x,y):
    return 0<=x and x<N and 0<=y and y<M

def move(dir):
    global x
    global y
    global cube

    x += dx[dir-1]
    y += dx[dir-1]


def reverse(dir):
    if dir==1:
        return 2
    elif dir == 2:
        return 1
    elif dir == 3:
        return 4
    else:
        return 3

for c in commands:
    move(c)
    if check_boundary(x,y):
        if board[x][y]: ## board의 숫자가 복사됨
            print(getTop(cube))
            cube = board[x][y]
            print(getTop(board[x][y]))
            board[x][y] = 0
        else: ## cube 하단면의 숫자가 복사됨
            print(getTop(0))
            board[x][y] = cube
    else:
        move(reverse(c))