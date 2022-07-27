# 참고 링크 : https://moon-gd.tistory.com/38
dirRow = [-1, -1, -1, 0, 1, 1, 1, 0]
dirCol = [-1, 0, 1, 1, 1, 0, -1, -1]

while True:
    row, col = map(int, input().split())

    # 종료 조건 (둘 다 0인 경우)
    if row + col == 0:
        break

    road = []
    # 입력 받기
    for _ in range(row):
        road.append(input())

    for i in range(row):
        for j in range(col):
            if road[i][j] == '*':
                road[i] += '*'
                continue
            else:
                count = 0
                for k in range(8):
                    # 허용 범위의 행에 존재할 때
                    if i + dirRow[k] < 0 or i + dirRow[k] >= row:
                        continue
                    # 허용 범위의 열에 존재할 때
                    if j + dirCol[k] >= col or j + dirCol[k] < 0:
                        continue
                    # 허용 범위 안에서 지뢰가 존재할 때
                    if road[i + dirRow[k]][j + dirCol[k]] == '*':
                        count += 1
            road[i] += str(count)

    for i in range(row):
        print(road[i][col:])
