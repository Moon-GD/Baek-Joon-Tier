# 참고 링크 : https://moon-gd.tistory.com/41
import sys
U, N = map(int, input().split())

input = sys.stdin.readline
auction_info = []
money = [0] * (U + 1)

for i in range(N):
    name, price = input().split()
    price = int(price)
    money[price] += 1
    auction_info.append((name, price))

minimum = money.index(min([i for i in money if i]))

for i in range(N):
    if auction_info[i][1] == minimum:
        print(auction_info[i][0], minimum)
        break