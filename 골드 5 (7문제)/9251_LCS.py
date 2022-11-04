# 설명 링크 : https://moon-gd.tistory.com/96
import sys
q_input = sys.stdin.readline  # 빠른 입력

# 문자열 입력
A = q_input().rstrip()
B = q_input().rstrip()

# 문자열 길이 계산
len_A, len_B = len(A), len(B)

if len_A == 0 or len_B == 0:
    print(0)
else:
    # DP 배열 생성
    dp = []
    for _ in range(len_B + 1):
        dp.append([0] * (len_A + 1))

    # DP 배열 계산
    for i in range(1, len_B + 1):
        for j in range(1, len_A + 1):
            if A[j - 1] == B[i - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    # 결과 출력
    print(dp[len_B][len_A])
