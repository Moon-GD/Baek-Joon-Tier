# 참고 링크 : https://moon-gd.tistory.com/40
# 첫 번째 행렬 입력 받기
row1, col1 = map(int, input().split())
first = []
for _ in range(row1):
    first.append(list(map(int, input().split())))
# 두 번째 행렬 입력 받기
row2, col2 = map(int, input().split())
second = []
for _ in range(row2):
    second.append(list(map(int, input().split())))

for i in range(row1):
    for j in range(col2):
        temp = 0
        for k in range(row2):
            temp = temp + first[i][k] * second[k][j]
        print(temp, end=' ')
    print()