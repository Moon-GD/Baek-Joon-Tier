# 설명 링크 : https://moon-gd.tistory.com/102
def find_gcd(a, b):
    smaller_one = min(a, b)

    for i in range(smaller_one, 0, -1):
        if a % i == 0 and b % i == 0:
            return i


num1, num2 = map(int, input().split())  # 입력 받기
gcd = find_gcd(num1, num2)  # 최대 공약수 구하기
lcm = num1 * num2 // gcd  # 최소 공배수 계산

# 결과 출력
print(gcd)
print(lcm)