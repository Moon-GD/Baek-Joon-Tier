count = 0
for i in range(1, 6):
    # 이름 입력받기
    name = input()

    # FBI 문자열이 발견되는 경우 요원 번호 출력
    if name.find("FBI") != -1:
        print(i)
    # 발견되지 않는 경우 count 변수 1 증가
    else:
        count += 1

# FBI 문자열이 하나도 발견되지 않는 경우 정해진 문자열 출력
if count == 5:
    print("HE GOT AWAY!")
