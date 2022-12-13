# 설명 링크 : https://moon-gd.tistory.com/104
import sys
q_input = sys.stdin.readline

size = int(q_input())
numbers = []

for i in range(size):
    numbers.append(int(q_input()))

numbers.sort()

for num in numbers:
    print(num)