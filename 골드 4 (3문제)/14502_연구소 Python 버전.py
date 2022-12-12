# 설명 링크 : https://moon-gd.tistory.com/100
from itertools import combinations
import copy  # 2차원 깊은 복사를 위해
import collections  # 큐

row_size, col_size = map(int, input().split())  # 크기 정보 입력

# 연구실 지도 입력
maps = []
for _ in range(row_size):
    maps.append(list(map(int, input().split())))


# 0과 2 자리 저장
zero_location = []
two_location = []
for i in range(row_size):
    for j in range(col_size):
        if maps[i][j] == 2:
            two_location.append([i, j])
        elif maps[i][j] == 0:
            zero_location.append([i, j])


# 방향 벡터
dir_row = [-1, 0, 1, 0]
dir_col = [0, 1, 0, -1]


def bfs(wall_pos):
    copy_map = copy.deepcopy(maps)
    copy_map[wall_pos[0][0]][wall_pos[0][1]] = 1
    copy_map[wall_pos[1][0]][wall_pos[1][1]] = 1
    copy_map[wall_pos[2][0]][wall_pos[2][1]] = 1

    two_count = len(two_location)
    deque = collections.deque([])

    for location in two_location:
        deque.append(location)

    while len(deque):
        cur_row, cur_col = deque.pop()

        for k in range(4):
            new_row = cur_row + dir_row[k]
            new_col = cur_col + dir_col[k]

            # Continue : 좌표 유효 범위를 벗어난 경우
            if new_row < 0 or new_col < 0 or new_row >= row_size or new_col >= col_size:
                continue

            # Continue : 이동할 수 없는 칸인 경우
            if copy_map[new_row][new_col]:
                continue

            deque.append([new_row, new_col])
            copy_map[new_row][new_col] = 2
            two_count += 1

    global minimum_two
    minimum_two = min(minimum_two, two_count)


minimum_two = row_size * col_size

# 벽 위치 후보군
walls = list(combinations(zero_location, 3))

for comb in walls:
    bfs(comb)


print(len(zero_location) - (minimum_two - len(two_location)) - 3)
