# 설명 링크 : https://moon-gd.tistory.com/75
import sys
q_input = sys.stdin.readline  # 빠른 입력을 위해

# 회의 개수 입력
size = int(q_input())

# 회의 정보 리스트
meetings = [[0, 0]]

# 회의 정보 입력
for _ in range(size):
    start, end = map(int, q_input().split())
    meetings.append([start, end])

meetings.sort(key=lambda x : (x[1], x[0]))

count = 1
last_index = meetings[1][1]

for i in range(2, size + 1):
    if meetings[i][0] < last_index:
        continue
    else:
        last_index = meetings[i][1]
        count += 1

print(count)
