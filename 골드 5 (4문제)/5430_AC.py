# 설명 링크 : https://moon-gd.tistory.com/82
import sys
from collections import deque

q_input = sys.stdin.readline  # 빠른 입력을 위해서
test_size = int(q_input())

for _ in range(test_size):
    command = q_input()
    size = int(q_input())

    error_flag = False
    reverse_flag = False

    # 숫자 배열 입력받기
    # 빈 배열이 아닌 경우
    if size:
        queue = deque(q_input()[1:-2].split(','))
    # 빈 배열인 경우
    else:
        queue = q_input()  # 빈 괄호 입력 받기
        queue = deque()  # Deck 생성

    # 함수 핸들링
    for c in command:
        if c == 'R':
            reverse_flag = not reverse_flag
        elif c == 'D':
            if len(queue) == 0:
                error_flag = True
                break

            if reverse_flag:
                queue.pop()
            else:
                queue.popleft()

    # Deck이 뒤집힌 경우
    if reverse_flag:
        queue.reverse()

    if error_flag:
        print('error')
    else:
        print('[' + ','.join(queue) + ']')


