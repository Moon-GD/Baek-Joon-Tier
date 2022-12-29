# 참고 링크 : https://moon-gd.tistory.com/66
size = int(input())  # 숫자 개수

dp = [0]  # DP 배열

numbers = list(map(int, input().split()))  # 숫자 목록 리스트로 저장
index = 1
for number in numbers:
    dp.append(dp[index - 1] + number) if dp[index - 1] + number > number else dp.append(number)
    index += 1

print(max(dp[1:]))
