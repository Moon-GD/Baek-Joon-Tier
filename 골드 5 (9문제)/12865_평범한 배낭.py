# 설명 링크 : https://moon-gd.tistory.com/77
import sys
q_input = sys.stdin.readline  # 빠른 입력

items_size, bag_weights = map(int, q_input().split())  # 가방 정보 입력
items_info = [[0, 0]]  # 물건 정보 리스트

# 물건 정보 입력 받기
for _ in range(items_size):
    items_info.append(list(map(int, q_input().split())))

# DP 배열 선언
tables = [[0] * (bag_weights + 1) for _ in range(items_size + 1)]

# DP 배열 업데이트 과정
for index in range(1, items_size + 1):
    for w in range(index, bag_weights + 1):
        if w >= items_info[index][0]:
            c1 = tables[index - 1][w]
            c2 = tables[index - 1][w - items_info[index][0]] + items_info[index][1]
            tables[index][w] = max(c1, c2)
        else:
            tables[index][w] = tables[index - 1][w]

# 최종 값 출력
print(tables[items_size][bag_weights])