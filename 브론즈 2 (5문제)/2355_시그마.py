# 참고 링크 : https://moon-gd.tistory.com/30
A, B = map(int, input().split())

# A가 B보다 큰 경우, 서로 바꿔준다
if A > B:
    A, B = B, A

# 결과 출력
print((A + B) * (B - A + 1) // 2)
