times = 0
for _ in range(4):
    times += int(input())

# 분 출력
print(times // 60)

# 초 출력
print(times % 60)