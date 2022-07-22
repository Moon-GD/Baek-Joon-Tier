# 참고 링크 : https://moon-gd.tistory.com/29
dot = 0

# 단계 입력받기
N = int(input())

dot = (N + 1) * N // 2 + (N + 1) ** 2

print(dot % 45678)