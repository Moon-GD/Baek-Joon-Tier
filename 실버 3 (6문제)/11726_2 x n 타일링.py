# 설명 링크 : https://moon-gd.tistory.com/141

# input : get size of the given rectangle
size = int(input())

# initialize : dp
dp = [0, 1, 2]

for i in range(3, size + 1):
    # initialize : i-th dp
    dp.append(dp[i - 1] + dp[i - 2])

    # update : i-th dp
    dp[i] = dp[i] % 10007

# result
print(dp[size])
