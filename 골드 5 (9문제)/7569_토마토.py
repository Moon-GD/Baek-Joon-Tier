# 설명 링크 : https://moon-gd.tistory.com/80
import sys
import collections
q_input = sys.stdin.readline  # 빠른 입력을 위해
queue = collections.deque([])

x_size, y_size, z_size = map(int, q_input().split())  # 토마토 상자 크기 확인

# 공간 정보 선언
total_size = x_size * y_size * z_size  # 토마토 상자 전체 칸 개수
empty_size = 0  # 빈 공간 수
colored_size = 0  # 익은 토마토가 있는 칸의 수

# 방문 리스트, 토마토 리스트
visited = [[[False for _ in range(x_size)] for _ in range(y_size)] for _ in range(z_size)]

tomatoes = []

for k in range(z_size):
    temp = []
    for j in range(y_size):
        temp.append([])
    tomatoes.append(temp)

# 방향 정보 리스트
dir_vector = [[0, 0, 1], [0, 0, -1], [0, -1, 0], [1, 0, 0], [0, 1, 0], [-1, 0, 0]]

# 정답 변수
target_day = 0

for k in range(z_size):
    for j in range(y_size):
        x_list = list(map(int, q_input().split()))
        tomatoes[k][j] = x_list
        for i in range(x_size):
            # 익은 토마토가 들어 있는 경우
            if x_list[i] == 1:
                colored_size += 1  # 색칠된 칸 개수 += 1
                queue.append([k, j, i, 0])  # 큐에 넣어주기
                visited[k][j][i] = True  # 방문 배열 체크

            # 빈 칸인 경우
            elif x_list[i] == -1:
                empty_size += 1  # 빈 칸 개수 += 1


while len(queue):
    cur_z, cur_y, cur_x, cur_day = queue.popleft()

    for vector in dir_vector:
        new_x = cur_x + vector[0]
        new_y = cur_y + vector[1]
        new_z = cur_z + vector[2]

        # continue : X 허용 범위를 벗어난 경우
        if new_x < 0 or new_x >= x_size:
            continue

        # continue : Y 허용 범위를 벗어난 경우
        if new_y < 0 or new_y >= y_size:
            continue

        # continue : Z 허용 범위를 벗어난 경우
        if new_z < 0 or new_z >= z_size:
            continue

        # continue : 이미 방문한 칸인 경우
        if visited[new_z][new_y][new_x]:
            continue

        # continue : 빈 칸을 방문한 경우
        if tomatoes[new_z][new_y][new_x] == -1:
            continue

        queue.append([new_z, new_y, new_x, cur_day + 1])
        visited[new_z][new_y][new_x] = True
        colored_size += 1
        target_day = cur_day + 1

if colored_size + empty_size == total_size:
    if colored_size:
        print(target_day)
    else:
        print(0)
else:
    print(-1)
