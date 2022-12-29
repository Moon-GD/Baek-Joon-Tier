# 참고 링크 : https://moon-gd.tistory.com/135
import sys
q_input = sys.stdin.readline  # 빠른 입력

size = int(q_input())

# 입력 : 종이 정보
squares = [list(map(int, q_input().split())) for _ in range(size)]

# 색종이 개수 초기화
white = 0
blue = 0

# 방문 정보 리스트 초기화
visited = []
for _ in range(size):
    temp_list = [False for _ in range(size)]
    visited.append(temp_list)


# 특정 영역의 색깔이 하나로 칠해져 있는지 판단해주는 함수
# 영역 내의 모든 색깔이 일치한다면? return True
# 다른 색깔이 존재한다면? return False
def search(cur_row, cur_col, cur_length):
    cur_color = squares[cur_row][cur_col]  # 현재 색상 정보 입력

    for ii in range(cur_row, cur_row + cur_length):
        for jj in range(cur_col, cur_col + cur_length):
            if squares[ii][jj] != cur_color:
                return False

    return True


# 정해진 영역의 모든 좌표를 방문 표시해주고 색종이 개수를 업데이트 해주는 함수
def visit(cur_row, cur_col, cur_length):
    for iii in range(cur_row, cur_row + cur_length):
        for jjj in range(cur_col, cur_col + cur_length):
            visited[iii][jjj] = True

    # 색종이 개수 업데이트
    if squares[cur_row][cur_col] == 1:
        global blue
        blue += 1
    else:
        global white
        white += 1


def solve():
    length = size

    while length:
        for i in range(0, size, length):
            for j in range(0, size, length):
                # continue : 이미 방문한 경우
                if visited[i][j]:
                    continue

                if search(i, j, length):
                    visit(i, j, length)

        length //= 2

    print(white)
    print(blue)


solve()
