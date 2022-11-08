# 설명 링크 : https://moon-gd.tistory.com/98
import sys
q_input = sys.stdin.readline  # 빠른 입력

size = int(q_input())  # 크기 입력

# 그래프 리스트 생성
graph = [[]]
for _ in range(size):
    graph.append([])

visited = [False for _ in range(size + 1)]  # 방문 리스트 생성
depth = [0 for _ in range(size + 1)]  # 트리 깊이 리스트 생성
sub_node = [0 for _ in range(size + 1)]

for _ in range(size - 1):
    v1, v2 = map(int, q_input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)

input_order = list(map(int, q_input().split()))
input_order.insert(0, 0)
if input_order[1] != 1:
    print(0)
    exit(0)


def dfs(vertex, level):
    if visited[vertex]:
        return 0
    else:
        visited[vertex] = True  # 방문 표시
        depth[vertex] = level  # 트리 깊이 저장

        child = 1
        for v in graph[vertex]:
            # 방문하지 않은 정점인 경우
            if not visited[v]:
                # DFS 탐색
                child += dfs(v, level + 1)

        sub_node[vertex] = child

        return child


dfs(1, 0)

flag = 1
for i in range(2, size + 1):
    if sub_node[input_order[i]] + i > size:
        continue
    else:
        next_vertex = input_order[sub_node[input_order[i]] + i]
        if depth[next_vertex] > depth[input_order[i]]:
            flag = 0
            break


print(flag)


