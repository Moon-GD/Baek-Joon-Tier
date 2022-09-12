# 설명 링크 : https://moon-gd.tistory.com/74
import sys
q_input = sys.stdin.readline  # 빠른 입력을 위해

row, col = map(int, q_input().split())

# 미로 정보 리스트
maze = [[]]

# 방향 정보 리스트
dir_row = [-1, 0, 1, 0]
dir_col = [0, 1, 0, -1]

# 큐
queue = [[1, 1, 1]]

# 방문 정보 담는 리스트
visited = [[False for _ in range(col + 1)] for _ in range(row + 1)]

for i in range(1, row + 1):
    temp = q_input()
    temp_list = ['0']

    for j in range(col):
        temp_list.append(temp[j])

    maze.append(temp_list)

while True:
    cur_row, cur_col, cur_count = queue.pop(0)

    # 목적지에 도착한 경우
    if cur_row == row and cur_col == col:
        print(cur_count)
        break
    # 아직 도착하지 못한 경우
    else:
        for i in range(4):
            new_row = cur_row + dir_row[i]
            new_col = cur_col + dir_col[i]

            # row 허용 범위를 벗어난 경우
            if new_row <= 0 or new_row > row:
                continue

            # col 허용 범위를 벗어난 경우
            if new_col <= 0 or new_col > col:
                continue

            # 지나갈 수 없는 곳인 경우
            if maze[new_row][new_col] == '0':
                continue

            # 이미 방문한 곳인 경우
            if visited[new_row][new_col]:
                continue

            # 위의 반례를 모두 통과하면
            # 큐에 넣고 방문 정보 표시
            queue.append([new_row, new_col, cur_count + 1])
            visited[new_row][new_col] = True
