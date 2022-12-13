# 참고 링크 : https://moon-gd.tistory.com/37
N = int(input())
vertex = []

# 입력 받기
for _ in range(N):
    first, second = map(int, input().split())
    vertex.append([first, second])

# 다중 리스트 정렬의 기준을
# 첫 번째 요소, 그 다음은 두 번째 요소로 잡고 정렬
vertex.sort(key=lambda x : (x[0], x[1]))

# 하나씩 출력
for i in vertex:
    print(i[0], i[1])