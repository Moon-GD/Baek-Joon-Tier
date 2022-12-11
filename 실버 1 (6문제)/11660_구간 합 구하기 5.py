# 설명 링크 : https://moon-gd.tistory.com/73
import sys
q_input = sys.stdin.readline # 빠른 입력을 위해서

# 정사각형 크기와 답 출력 횟수 입력
size, times = map(int, q_input().split())

# 누적 합 배열 저장
sums = [[0 for _ in range(size + 1)] for _ in range(size + 1)]

for i in range(1, size + 1):
    numbers = list(map(int, q_input().split()))

    # 누적 합 계산
    for j in range(1, size + 1):
        sums[i][j] = sums[i - 1][j] + sums[i][j-1] - sums[i - 1][j - 1] + numbers[j - 1]


for _ in range(times):
    start_row, start_col, end_row, end_col = map(int, q_input().split())

    print(
        sums[end_row][end_col]
        - sums[start_row - 1][end_col] - sums[end_row][start_col - 1]
        + sums[start_row - 1][start_col - 1]
    )