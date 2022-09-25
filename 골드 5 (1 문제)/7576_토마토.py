# 설명 링크 : https://moon-gd.tistory.com/76
import sys
from collections import deque

# 빠른 입력을 위해서
q_input = sys.stdin.readline

col, row = map(int, q_input().split())

# 필요한 리스트 선언
tomatoes = [['X'] * (col + 2)]  # 토마토 상자 정보
queue = deque([])  # 큐
dirVector = [[-1, 0], [0, 1], [1, 0], [0, -1]]  # 방향 벡터

# 영역 정보
colored_space = 0
empty_space = 0
total_space = row * col

for i in range(1, row + 1):
    temp_list = list(map(int, q_input().split()))
    tomatoes.append(['X'] + temp_list + ['X'])

    for j in range(1, col + 1):
        if tomatoes[i][j] == 1:
            colored_space += 1
            queue.append([i, j, 0])

        elif tomatoes[i][j] == -1:
            empty_space += 1

tomatoes.append(['X'] * (col + 2))

day = 0

while len(queue):
    cur_row, cur_col, cur_day = queue.popleft()

    for i in range(4):
        new_row = cur_row + dirVector[i][0]
        new_col = cur_col + dirVector[i][1]

        if tomatoes[new_row][new_col] == 0:
            tomatoes[new_row][new_col] = 1
            queue.append([new_row, new_col, cur_day + 1])
            colored_space += 1
            day = cur_day + 1

if colored_space + empty_space == total_space:
    if colored_space:
        print(day)
    else:
        print(0)
else:
    print(-1)