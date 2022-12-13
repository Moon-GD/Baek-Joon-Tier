# 설명 링크 : https://moon-gd.tistory.com/137
import sys

q_input = sys.stdin.readline  # 빠른 입력을 위해

M = int(q_input())

numbers = [False for _ in range(21)]

for _ in range(M):
    command = q_input()

    # add, all
    if command[0] == 'a':
        # add
        if command[1] == 'd':
            number = int(command[4:])
            numbers[number] = True

        # all
        else:
            numbers = [True for _ in range(21)]

    # remove
    elif command[0] == 'r':
        number = int(command[7:])
        numbers[number] = False

    # check (출력 발생하는 분기문)
    elif command[0] == 'c':
        number = int(command[6:])

        # 있는 경우
        if numbers[number]:
            print(1)
        # 없는 경우
        else:
            print(0)

    # empty
    elif command[0] == 'e':
        numbers = [False for _ in range(21)]

    # toggle
    elif command[0] == 't':
        number = int(command[7:])
        numbers[number] = not numbers[number]
