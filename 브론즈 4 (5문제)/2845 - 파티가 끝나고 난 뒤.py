person, area = map(int, input().split())

news = input().split()

for i in news:
    print(int(i) - person * area, end=' ')