# 설명 링크 : https://moon-gd.tistory.com/138
import sys

q_input = sys.stdin.readline  # 빠른 입력을 위해

N, M = map(int, q_input().rstrip().split())

monsters = [[]]
monsters_sorted = []
for i in range(1, N + 1):
    info = [q_input().rstrip(), i]
    monsters.append(info)
    monsters_sorted.append(info)

monsters_sorted.sort()


def binary_search(size, target_name):
    left = 0
    right = size - 1

    while left <= right:
        middle = (left + right) // 2

        if monsters_sorted[middle][0] == target_name:
            return monsters_sorted[middle][1]
        elif monsters_sorted[middle][0] > target_name:
            right = middle - 1
        else:
            left = middle + 1


for _ in range(M):
    find_string = q_input().rstrip()

    # 숫자인 경우
    if '0' <= find_string[0] <= '9':
        find_string = int(find_string)
        print(monsters[int(find_string)][0])

    # 문자열인 경우
    else:
        print(binary_search(N, find_string))
