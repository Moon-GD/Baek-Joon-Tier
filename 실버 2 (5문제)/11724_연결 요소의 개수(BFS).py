# 참고 링크 : https://moon-gd.tistory.com/67
import sys
q_input = sys.stdin.readline  # 빠른 입력을 위해

# 정점, 간선 개수 입력받기
vertex, edge = map(int, q_input().split())

# 연결 정보 배열
connect = []
for _ in range(vertex + 1):
    connect.append([])

# 방문 정보 배열
visited = [False for _ in range(vertex + 1)]

# 입력 받기 + 연결 정보 저장
for _ in range(edge):
    v1, v2 = map(int, q_input().split())
    connect[v1].append(v2)
    connect[v2].append(v1)

sol = 0
for v in range(1, vertex + 1):
    # 방문한 배열이면 pass
    if visited[v]:
        continue
    else:
        stack = [v]
        while len(stack):
            start = stack.pop()
            for i in connect[start]:
                if visited[i]:
                    continue
                else:
                    stack.append(i)
                    visited[i] = True  # ** 스택에 넣음과 동시에 방문 정보를 True로 설정하는게 포인트!! **

        # 한 번 BFS 끝나면 연결 요소 개수 추가
        sol += 1


# 정답 출력
print(sol)