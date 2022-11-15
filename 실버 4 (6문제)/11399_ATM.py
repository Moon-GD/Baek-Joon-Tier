# 참고 링크 : https://moon-gd.tistory.com/44
# 크기 입력 받기
size = int(input())

# 시간 정보 오름차순으로 정렬해서 리스트에 저장하기
times = sorted(list(map(int, input().split())))

# 정렬된 리스트 순회하며 누적 시간 합 계산하기
min_time = 0
for i in range(0, size):
    min_time += times[i] * (size - i)

print(min_time)