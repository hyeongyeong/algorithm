from sys import stdin
from collections import deque

def check_boundary(N, x,y) :
    return True if 0 <= x and x<N and 0<=y and y<N else False


def change_direction(dir, d):
    if dir == "D" :
        d = (d+1)%4
    else:
        d = (d-1)%4
    return d

def main():

    N = int(input())
    matrix = [[0]*N for _ in range(N)]

    for _ in range(int(input())):
        r,c = map(int,input().split())
        matrix[r-1][c-1] = 1

    change = {}
    for _ in range(int(input())):
        x,c = input().split()
        change[int(x)] = c

    snake = deque()
    snake.append([0,0])

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    d = 1
    time = 0
    nx, ny = 0, 0

    while True:
        time +=1
        nx += dx[d]
        ny += dy[d]

        if time in change.keys():
            d = change_direction(change[time], d)
        
        if check_boundary(N, nx,ny):
            if [nx,ny] in snake:
                break

            if matrix[nx][ny] == 1:
                matrix[nx][ny] = 0
                snake.append([nx,ny])

            elif matrix[nx][ny] == 0:
                snake.append([nx,ny])
                snake.popleft()
        else:
            break

    print(time)

main()


