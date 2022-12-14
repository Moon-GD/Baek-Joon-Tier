# 설명 링크 : https://moon-gd.tistory.com/138
import sys

q_input = sys.stdin.readline  # 빠른 입력을 위해

N, M = map(int, q_input().rstrip().split())

monsters = [[]]
monsters_dic = {}


for i in range(1, N + 1):
    name = q_input().rstrip()
    monsters.append(name)
    monsters_dic[name] = i

for _ in range(M):
    find_string = q_input().rstrip()

    # 숫자인 경우
    if '0' <= find_string[0] <= '9':
        find_string = int(find_string)
        print(monsters[find_string])

    # 문자열인 경우
    else:
        print(monsters_dic[find_string])
