# 참고 링크 : https://moon-gd.tistory.com/71
import sys
q_input = sys.stdin.readline  # 빠른 입력을 받기 위해서

size = int(q_input())

red_array = [0]
green_array = [0]
blue_array = [0]

for i in range(size):
    red, green, blue = map(int, q_input().split())

    # red 배열 갱신
    if green_array[i] < blue_array[i]:
        red_array.append(red + green_array[i])
    else:
        red_array.append(red + blue_array[i])

    # green 배열 갱신
    if red_array[i] < blue_array[i]:
        green_array.append(green + red_array[i])
    else:
        green_array.append(green + blue_array[i])

    # blue 배열 갱신
    if red_array[i] < green_array[i]:
        blue_array.append(blue + red_array[i])
    else:
        blue_array.append(blue + green_array[i])

print(min(red_array[-1], green_array[-1], blue_array[-1]))