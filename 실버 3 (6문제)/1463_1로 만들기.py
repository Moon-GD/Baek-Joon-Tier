# 참고 링크 : https://moon-gd.tistory.com/49
size = int(input())

# size = 1
if size == 1:
    print(0)
# size = 2, 3
elif size <= 3:
    print(1)
# size = 4, 5, 6 ...
else:
    dp = [0] * (size + 1)
    dp[2] = dp[3] = 1
    for i in range(4, size + 1):
        # 우선 i - 1 번째 값 저장 + 1
        dp[i] = dp[i - 1] + 1

        if i % 2 == 0 and dp[i // 2]:
            dp[i] = min(dp[i], dp[i // 2] + 1)

        if i % 3 == 0 and dp[i // 3]:
            dp[i] = min(dp[i], dp[i // 3] + 1)

    print(dp[size])
