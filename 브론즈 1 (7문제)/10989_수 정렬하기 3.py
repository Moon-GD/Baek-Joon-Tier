# 참고 링크 : https://moon-gd.tistory.com/33
import sys

count = [0] * 10001
N = int(input())

for _ in range(N):
    count[int(sys.stdin.readline())] += 1

for i in range(1, 10001):
    for _ in range(count[i]):
        print(i)
