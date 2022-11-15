# 참고 링크 : https://moon-gd.tistory.com/47
import sys
q_input = sys.stdin.readline
size = int(q_input())
numbers = set(list(map(int, q_input().split())))

output_size = int(q_input())
output_list = list(map(int, q_input().split()))


for number in output_list:
    if number in numbers:
        print(1)
    else:
        print(0)