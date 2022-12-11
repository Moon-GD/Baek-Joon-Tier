# 설명 링크 : https://moon-gd.tistory.com/132
N, row, col = map(int, input().split())

length = 2 ** N
count = 0

while length != 2:
    is_up = True
    is_left = True

    # 사분면 위치 계산 1
    if row >= length // 2:
        row -= length // 2
        is_up = False

    # 사분면 위치 계산 2
    if col >= length // 2:
        col -= length // 2
        is_left = False

    # count 계산
    if is_up and is_left:
        count += 0
    elif is_up and not is_left:
        count += length * length // 4
    elif not is_up and is_left:
        count += length * length // 2
    elif not is_up and not is_left:
        count += length * length // 4 * 3

    length //= 2

# 길이가 2인 배열만 남았을 때...
# 좌표가 왼쪽 위인 경우
if row == 0 and col == 0:
    count += 0
    
# 좌표가 오른쪽 위인 경우
elif row == 0 and col == 1:
    count += 1
    
# 좌표가 왼쪽 아래인 경우
elif row == 1 and col == 0:
    count += 2
    
# 좌표가 오른쪽 아래인 경우
elif row and col:
    count += 3

# 이동 횟수 출력
print(count)
