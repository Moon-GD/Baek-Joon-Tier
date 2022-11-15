# 참고 링크 : https://moon-gd.tistory.com/42
import sys
input = sys.stdin.readline
size = int(input())

for _ in range(size):
    string = input()

    # 괄호 문자 카운팅 변수
    # 왼쪽 괄호가 들어오는 경우 1을 증가
    # 오른쪽 괄호가 들어오는 경우 1을 감소
    count = 0
    for c in string:
        if c == '(':
            count += 1
        elif c == ')':
            count -= 1
        if count < 0:
            break
    if count == 0:
        print('YES')
    else:
        print('NO')