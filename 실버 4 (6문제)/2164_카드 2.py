# 설명 링크 : https://moon-gd.tistory.com/103
from collections import deque
size = int(input())  # 크기 입력 받기

# 큐 만들기
queue = deque([i for i in range(1, size + 1)])

while len(queue) != 1:
    queue.popleft()
    queue.append(queue.popleft())

print(queue[0])
