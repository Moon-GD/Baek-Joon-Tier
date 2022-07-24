# 참고 링크 : https://moon-gd.tistory.com/35
test_size = int(input())

for i in range(1, test_size + 1):
    print(f'Scenario #{i}:')

    # 단어 정보 입력받기
    word_count = int(input())
    word = []
    for _ in range(word_count):
        word.append(input())

    # 참가자 정보 입력받기
    player_count = int(input())

    for _ in range(player_count):
        password = list(map(int, input().split()))
        for p in password[1:]:
            print(f'{word[p]}', end='')
        print('')
    print('')