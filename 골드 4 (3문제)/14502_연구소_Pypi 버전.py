# 설명 링크 : https://moon-gd.tistory.com/100
import sys
import copy
import collections
q_input = sys.stdin.readline  # 빠른 입력

row_size, col_size = map(int, q_input().split())  # 크기 입력

# 지도 입력
maps = []
for _ in range(row_size):
    maps.append(list(map(int, q_input().split())))

# 방향 벡터
dir_row = [-1, 0, 1, 0]
dir_col = [0, 1, 0, -1]

two_locations = []

# 기존 맵 파악
two_count = 0
one_count = 0
for i in range(row_size):
    for j in range(col_size):
        if maps[i][j] == 2:
            two_count += 1
            two_locations.append([i, j])
        elif maps[i][j] == 1:
            one_count += 1


def bfs():
    copy_map = copy.deepcopy(maps)
    one = one_count + 3
    two = two_count

    deque = collections.deque([])
    for location in two_locations:
        deque.append(location)

    while len(deque):
        cur_row, cur_col = deque.pop()

        for k in range(4):
            new_row = cur_row + dir_row[k]
            new_col = cur_col + dir_col[k]

            # Continue : 유효 row 범위를 벗어난 경우
            if new_row < 0 or new_row >= row_size:
                continue

            # Continue : 유효 col 범위를 벗어난 경우
            if new_col < 0 or new_col >= col_size:
                continue

            # Continue : 이동할 수 없는 구간인 경우
            if copy_map[new_row][new_col]:
                continue

            two += 1
            copy_map[new_row][new_col] = 2
            deque.append([new_row, new_col])

    global safe_area
    safe_area = max(safe_area, row_size * col_size - one - two)


def choose(depth):
    if depth == 3:
        bfs()
        return
    else:
        for i in range(row_size):
            for j in range(col_size):
                if maps[i][j] == 0:
                    maps[i][j] = 1
                    choose(depth + 1)
                    maps[i][j] = 0


safe_area = 0
choose(0)

print(safe_area)