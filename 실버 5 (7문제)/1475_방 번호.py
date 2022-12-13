# 참고 링크 : https://moon-gd.tistory.com/39
N = int(input())
numbers = [0 for _ in range(10)]

while N:
    numbers[N % 10] += 1
    N //= 10

if (numbers[6] + numbers[9]) % 2 == 1:
    numbers[6] = (numbers[6] + numbers[9] + 1) // 2
else:
    numbers[6] = (numbers[6] + numbers[9]) // 2

print(max(numbers[:9]))
