# 참고 링크 : https://moon-gd.tistory.com/54
import sys
q_input = sys.stdin.readline

# stack 정보
stack = []

pc = int(q_input())  # 컴퓨터 수
connect = int(q_input())  # 연결 개수

# network 정보
network = []
for _ in range(pc + 1):
    temp_list = []
    for _ in range(pc + 1):
        temp_list.append(0)
    network.append(temp_list)

# 방문 정보
visited = [False] * (pc + 1)

# 연결 정보 입력 받기
for _ in range(connect):
    com1, com2 = map(int, q_input().split())
    network[com1][com2] += 1
    network[com2][com1] += 1

# 1번 컴퓨터 넣기
stack.append(1)

# 감염 컴퓨터 수
count = -1

while True:
    # stack에서 빼낼 게 없는 경우
    if len(stack) <= 0:
        break

    pc_number = stack[-1]
    del stack[-1]

    if not visited[pc_number]:
        visited[pc_number] = True
        count += 1

    for i in range(1, pc + 1):
        # 연결되어 있는데
        if network[pc_number][i]:
            if visited[i]:
                continue
            # 방문되지 않았다면
            stack.append(i)

print(count)