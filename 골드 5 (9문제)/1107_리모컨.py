# 설명 링크 : https://moon-gd.tistory.com/105
target_channel = int(input())  # 목표 채널

err_size = int(input())  # 버튼 길이
if err_size >= 1:
    err_buttons = list(map(int, input().split()))  # 고장난 버튼 리스트
else:
    err_buttons = []

# Return : 목표 채널이 100번인 경우
if target_channel == 100:
    print(0)
    exit(0)

count = abs(100 - target_channel)  # 이동 횟수 초기화

for i in range(1000001):
    flag = True
    temp_num = i
    while True:
        # 에러 버튼이 포함된 숫자인 경우 Flag 표시 후 while 탈출
        if temp_num % 10 in err_buttons:
            flag = False
            break
        else:
            temp_num //= 10

        # while 탈출 조건
        if temp_num == 0:
            break

    if flag:
        length = min(len(str(i)), abs(i - 100))  # 채널 움직인 거리 계산
        count = min(count, abs(i - target_channel) + length)
        if i > target_channel:
            break

print(count)
