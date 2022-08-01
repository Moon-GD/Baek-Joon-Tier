# 참고 링크 : https://moon-gd.tistory.com/50
zeros = [0] * 41
ones = [0] * 41
zeros[0] = 1
ones[1] = 1

for i in range(2, 41):
    zeros[i] = zeros[i - 1] + zeros[i - 2]
    ones[i] = ones[i - 1] + ones[i - 2]

import sys
input = sys.stdin.readline

test_num = int(input())

for _ in range(test_num):
    num = int(input())
    print(zeros[num], ones[num])