# 설명 링크 : https://moon-gd.tistory.com/72
import sys
from collections import deque

q_input = sys.stdin.readline  # 빠른 입력을 받기 위해

test_num = int(q_input())  # 테스트 케이스 개수 입력

# 이동 정보에 관한 리스트
move_dir = [
    (1, 2), (2, 1), (2, -1), (1, -2),
    (-1, -2), (-2, -1), (-2, 1), (-1, 2)
]

# 테스트 케이스의 수 만큼 반복
for _ in range(test_num):
    size = int(q_input())  # 체스판 크기 입력
    cur_x, cur_y = map(int, q_input().split())  # 현재 좌표 입력
    goal_x, goal_y = map(int, q_input().split())  # 목적지 좌표 입력

    # 방문 리스트 생성
    visited = [[False for _ in range(size)] for _ in range(size)]

    # Queue 생성
    queue = deque([(cur_x, cur_y, 0)])

    while True:
        x, y, count = queue.popleft()

        # 목적 좌표에 도착한 경우
        if x == goal_x and y == goal_y:
            # 이동 횟수를 출력하고 While 문 탈출
            print(count)
            break
        else:
            for i in range(8):
                # 새로운 좌표 생성
                new_x = x + move_dir[i][0]
                new_y = y + move_dir[i][1]

                # 새로운 좌표 검사
                # X 허용 범위를 벗어난 경우
                if new_x < 0 or new_x >= size:
                    continue

                # Y 허용 범위를 벗어난 경우
                if new_y < 0 or new_y >= size:
                    continue

                # 이미 방문한 좌표인 경우
                if visited[new_x][new_y]:
                    continue

                # 위의 반례에 해당하지 않는다면 Enque
                queue.append([new_x, new_y, count + 1])

                # 방문 배열 갱신
                visited[new_x][new_y] = True
