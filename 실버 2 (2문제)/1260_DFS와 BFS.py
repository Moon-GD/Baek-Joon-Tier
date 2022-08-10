# 참고 링크 : https://moon-gd.tistory.com/60
import queue
import sys

q_input = sys.stdin.readline
myQueue = queue.Queue()

vertex, edge, start = map(int, q_input().split())

# 연결 정보 저장할 배열 생성
connect = []

# 방문 배열 생성
dfs_visited = []
bfs_visited = []

for _ in range(vertex + 1):
    connect.append([])
    dfs_visited.append(False)
    bfs_visited.append(False)


# 연결 정보 저장하기
for _ in range(edge):
    v1, v2 = map(int, q_input().split())
    connect[v1].append(v2)
    connect[v2].append(v1)


for i in range(1, vertex + 1):
    connect[i].sort()


def dfs(point):
    dfs_visited[point] = True
    print(point, end=' ')

    for i in connect[point]:
        if not dfs_visited[i]:
            dfs(i)


# dfs 실행
dfs(start)

# 개행 출력
print()

# BFS
myQueue.put(start)
bfs_visited[start] = True


while myQueue.qsize():
    v = myQueue.get()
    print(v, end=' ')

    for i in connect[v]:
        if bfs_visited[i]:
            continue

        myQueue.put(i)
        bfs_visited[i] = True
