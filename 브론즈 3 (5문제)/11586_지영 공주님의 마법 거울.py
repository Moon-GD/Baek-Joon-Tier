# 거울 크기 입력 받기
size = int(input())

# 거울 정보 입력 받기
princess = [input() for _ in range(size)]

# 숫자 입력 받기
num = int(input())

if num == 2:
    princess = [string[::-1] for string in princess]
elif num == 3:
    princess.reverse()

# 출력
for string in princess:
    print(string)