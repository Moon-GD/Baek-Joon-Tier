# 참고 링크 : https://moon-gd.tistory.com/63
import sys

q_input = sys.stdin.readline  # 빠른 입출력을 위한

size = int(q_input())

sequence = list(map(int, q_input().split()))  # 수열 입력 받아서 저장
dp = [0]

# 수열을 처음부터 순회하면서 각 지점까지의 최대 길이를 구합니다
for i in range(size):
    number = sequence[i]  # sequence.pop(0) 해도 무방

    # 첫 순회에서는 DP 정보가 저장되어 있지 않으니 number를 넣어줍니다.
    if i == 0:
        dp[0] = number
    # 두 번째 순회부터는 아래의 분기문을 따릅니다.
    else:
        # 현재 DP에 저장된 최대 원소보다 더 큰 수인 경우, 그대로 추가해줍니다.
        # 즉, 그대로 이어주는 겁니다.
        # ex) dp = [10, 20, 30], number = 50 -> dp = [10, 20, 30, 50]
        if number > dp[-1]:
            dp.append(number)
        # 현재 DP에 저장된 최대 원소보다는 작은 경우, 아래의 분기문을 따릅니다.
        else:
            # DP 배열을 저장하면서 현재의 숫자가 안착할 수 있는 위치를 찾습니다.
            for j in range(len(dp)):
                # 찾은 경우, 적당한 숫자를 해당 인덱스에 넣어주고 반복문을 종료합니다.
                # ex ) dp = [10, 20], number = 15 -> dp = [10, 15]
                if dp[j] >= number:
                    dp[j] = number
                    break

# 수열의 모든 숫자를 순회한 이후에는 DP 길이를 출력합니다.
print(len(dp))