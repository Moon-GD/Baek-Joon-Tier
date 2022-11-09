# 설명 링크 : https://moon-gd.tistory.com/99
def validity(depth):
    for i in range(1, depth):
        if depth - i == abs(columns[depth] - columns[i]):
            return False

    return True


def queen(depth):
    if depth == size:
        global goal
        goal = goal + 1
    else:
        for j in range(1, size + 1):
            if visited[j]:
                continue

            columns[depth + 1] = j
            if validity(depth + 1):
                visited[j] = True
                queen(depth + 1)
                visited[j] = False


size = int(input())
goal = 0

columns = [0 for _ in range(size + 1)]
visited = [False for _ in range(size + 1)]

queen(0)
print(goal)
