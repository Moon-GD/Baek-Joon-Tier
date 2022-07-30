# 참고 링크 : https://moon-gd.tistory.com/48
import sys
q_input = sys.stdin.readline

size = int(q_input())
stack = []

for _ in range(size):
    number = int(q_input())

    # 정상적으로 수가 들어온 경우
    if number:
        stack.append(number)
    # 0이 들어온 경우
    else:
        del stack[-1]

print(sum(stack))