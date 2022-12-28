# 참고 링크 : https://moon-gd.tistory.com/55
import sys
q_input = sys.stdin.readline  # 빠른 입력을 위해서

size = int(q_input())

scores = [0] * (size + 1)
stairs = [0] * (size + 1)

# 입력 받기
for i in range(1, size + 1):
    scores[i] = int(q_input())

# size == 1 인 경우, Easy
stairs[1] = scores[1]

# size > 1 인 경우 DP를 통해서 계산
if size > 1:
    stairs[2] = scores[1] + scores[2]

    for i in range(3, size + 1):
        stairs[i] = max(stairs[i - 2] + scores[i], stairs[i - 3] + scores[i - 1]+scores[i])

print(stairs[size])
