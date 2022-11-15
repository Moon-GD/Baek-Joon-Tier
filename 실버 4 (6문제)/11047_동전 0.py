# 참고 링크 : https://moon-gd.tistory.com/45
import sys
# 필요 정보 입력받기
input = sys.stdin.readline
size, target_value = map(int, input().split())
coins = [int(input()) for _ in range(size)]

count = 0

for i in range(size - 1, -1, -1):
    count += target_value // coins[i]
    target_value %= coins[i]

print(count)
