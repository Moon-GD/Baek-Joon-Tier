# 참고 링크 : https://moon-gd.tistory.com/67
import sys
q_input = sys.stdin.readline  # 빠른 입출력 준비

# 정점, 간선 개수 저장
vertex, edge = map(int, q_input().split())

# 부모 배열, 노드 개수 배열, 방문 배열 생성
parent = [v for v in range(vertex + 1)]
count = [1 for _ in range(vertex + 1)]
visited = [False for _ in range(vertex + 1)]


# 부모 정보 찾는 함수
def find_parent(v):
    if parent[v] == v:
        return v
    else:
        parent_v = find_parent(parent[v])
        parent[v] = parent_v
        return parent[v]


# 두 정점 합치는 함수
def union(a, b):
    parent_a = find_parent(a)
    parent_b = find_parent(b)

    # 같은 소속이면 return
    if parent_a == parent_b:
        return
    # a가 더 많은 경우 a 쪽으로 병합
    elif count[parent_a] > count[parent_b]:
        count[parent_b] = 0
        count[parent_a] += 1
        parent[b] = parent_a

    # b가 더 많은 경우 b 쪽으로 병합
    else:
        count[parent_a] = 0
        count[parent_b] += 1
        parent[a] = parent_b


# 정점 입력 받기 + union
for _ in range(edge):
    v1, v2 = map(int, q_input().split())
    union(v1, v2)

# 연결 요소 개수 찾기
sol = 0
for v in range(1, vertex + 1):
    # 노드가 달려있는 정점만 검사
    if count[v]:
        # 부모 노드 찾기
        parent_v = find_parent(v)

        # 방문한 적이 있으면 continue
        if visited[parent_v]:
            continue

        # 방문한 적이 없을 경우 방문 정보 남기기 + 연결 요소 한 개 추가
        else:
            visited[parent_v] = True
            sol += 1

# 답 출력
print(sol)
