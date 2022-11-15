# 설명 링크 : https://moon-gd.tistory.com/101
while True:
    number = input()  # 숫자 입력 받기 (정확히는, String type)

    # break : 0인 경우 while 탈출
    if number == '0':
        break
    # 뒤집었을 때 서로 똑같은 경우 yes 출력
    elif number == number[::-1]:
        print('yes')

    # 그 밖에 모든 경우 no 출력
    else:
        print('no')
