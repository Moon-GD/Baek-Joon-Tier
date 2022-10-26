# 설명 링크 : https://moon-gd.tistory.com/95
import collections
import sys

# 큐 생성
deque = collections.deque()

# 빠른 입력
q_input = sys.stdin.readline

# 그림 배열
drawings = []

# 탐색 방향 배열
dir_x = [0, 1, 0, -1]
dir_y = [1, 0, -1, 0]

# 결과 변수
goal = 0
goal_type = 0

# 그림 크기와 정보 입력
size = int(q_input())
for _ in range(size):
    drawings.append(list(input()))

# 방문 배열 생성
isVisited = [[False] * size for _ in range(size)]


# BFS 탐색
def BFS(start_color):
    while len(deque):
        x, y = deque.popleft()
        
        for k in range(4):
            new_x = x + dir_x[k]
            new_y = y + dir_y[k]
            # Continue : X 허용 범위를 벗어난 경우
            if new_x < 0 or new_x >= size:
                continue

            # Continue : Y 허용 범위를 벗어난 경우
            if new_y < 0 or new_y >= size:
                continue

            # Continue : 이미 방문한 칸인 경우
            if isVisited[new_x][new_y]:
                continue

            # 같은 색상의 칸을 방문한 경우 큐에 추가
            if drawings[new_x][new_y] == start_color:
                deque.append([new_x, new_y])
                isVisited[new_x][new_y] = True


# 일반 사람의 경우 탐색
for i in range(size):
    for j in range(size):
        if not isVisited[i][j]:
            deque.append([i, j])
            isVisited[i][j] = True
            goal += 1
            BFS(drawings[i][j])


# 적록색약 탐색
# 방문 배열 초기화
isVisited = [[False] * size for _ in range(size)]

# 그래프 변환
for i in range(size):
    for j in range(size):
        if drawings[i][j] == 'R':
            drawings[i][j] = 'G'


# 적록색약의 경우 탐색
for i in range(size):
    for j in range(size):
        if not isVisited[i][j]:
            deque.append([i, j])
            isVisited[i][j] = True
            goal_type += 1
            BFS(drawings[i][j])

# 결과 출력
print(goal, goal_type)
