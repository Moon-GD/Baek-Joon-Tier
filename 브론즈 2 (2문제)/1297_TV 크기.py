# 참고 링크 : // 참고 링크 : https://moon-gd.tistory.com/27
# TV 정보 입력 받기
Diagonal, Height, Width = map(int, input().split())

# 피타고라스 법칙을 활용해서 비율 계산
ratio = (Diagonal ** 2 / (Height ** 2 + Width ** 2)) ** 0.5

# 계산된 비율에 맞춰서 높이, 너비 순으로 출력
print(int(ratio * Height), int(ratio * Width))