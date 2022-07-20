hour, minute, sec = map(int, input().split())
cook_time = int(input())

sec += cook_time

# 60초 미만으로 올바르게 시간 설정이 될 때까지 반복14
while sec >= 60:
    sec -= 60
    minute += 1

    # minute이 허용 범위를 벗어날 경우
    if minute >= 60:
        minute = 0
        hour += 1

    # hour이 허용 범위를 벗어날 경우
    if hour >= 24:
        hour = 0

print(hour, minute, sec)
