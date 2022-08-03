# 참고 링크 : https://moon-gd.tistory.com/52
count = [0] * 11

count[1] = 1
count[2] = 2
count[3] = 4
for i in range(4, 11):
    count[i] = count[i - 1] + count[i - 2] + count[i - 3]

import sys
q_input = sys.stdin.readline

test_num = int(q_input())

for _ in range(test_num):
    print(count[int(q_input())])
