# 참고 링크 : https://moon-gd.tistory.com/58
import sys
sys.setrecursionlimit(10000)  # 재귀 깊이 10000 설정
q_input = sys.stdin.readline  # 빠른 입력을 받기 위한 준비

testcase = int(q_input())

dir_x = [0, 1, 0, -1]
dir_y = [-1, 0, 1, 0]
parent = []
ground = []
parent_index = 1

for _ in range(51):
    temp_list1 = []
    temp_list2 = []
    for _ in range(51):
        temp_list1.append(0)
        temp_list2.append(0)
    parent.append(temp_list1)
    ground.append(temp_list2)


def bfs(X, Y):
    # 종료 조건 : 이미 소속된 땅이 존재하는 경우
    if parent[X][Y]:
        return
    else:
        parent[X][Y] = parent_index
        for i in range(4):
            new_X = X + dir_x[i]
            new_Y = Y + dir_y[i]

            # continue : 유효 범위를 벗어난 경우 1
            if new_X < 0 or new_X >= x_size:
                continue

            # continue : 유효 범위를 벗어난 경우 2
            if new_Y < 0 or new_Y >= y_size:
                continue

            if ground[new_X][new_Y]:
                bfs(new_X, new_Y)



for _ in range(testcase):
    x_size, y_size, connect_size = map(int, q_input().split())

    stack = []
    parent_index = 1

    # 배추 정보 입력받기
    for _ in range(connect_size):
        x, y = map(int, q_input().split())
        stack.append([x, y])
        ground[x][y] = 1


    for i in range(connect_size):
        x, y = stack[i][0], stack[i][1]

        # continue : 이미 속한 구역이 있을 경우
        if parent[x][y]:
            continue
        bfs(x, y)
        parent_index = parent_index + 1

    print(parent_index - 1)

    # 초기화 과정
    for y in range(y_size):
        for x in range(x_size):
            parent[x][y] = 0
            ground[x][y] = 0
