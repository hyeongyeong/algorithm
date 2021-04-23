
## input
N, M, x, y, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
commands = list(map(int, input().split()))

# direction
# 좌 우 상 하
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]

cube = [0]*6
cur = 0

def check_boundary(x,y):
    return 0<=x and x<N and 0<=y and y<M

def move(dir):
    global x
    global y
    global cube

    x += dx[dir-1]
    y += dy[dir-1]

    if dir == 1: # 동
        cube = [cube[2],cube[1],cube[5],cube[0],cube[4],cube[3]]
    elif dir == 2: # 서
        cube = [cube[3],cube[1],cube[0],cube[5],cube[4],cube[2]]
    elif dir == 3: # 북
        cube = [cube[4],cube[0],cube[2],cube[3],cube[5],cube[1]]
    else : # 남
        cube = [cube[5],cube[4],cube[2],cube[3],cube[1],cube[0]]


for c in commands:
    if check_boundary(x+dx[c-1],y+dy[c-1]):
        move(c)
        if board[x][y]: ## board의 숫자가 복사됨
            cube[0] = board[x][y]
            board[x][y] = 0
            print(cube[5])
        else: ## cube 하단면의 숫자가 복사됨
            board[x][y] = cube[0]
            print(cube[5])
