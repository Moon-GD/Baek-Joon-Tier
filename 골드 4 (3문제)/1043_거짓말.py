# 설명 링크 : https://moon-gd.tistory.com/133
import sys
q_input = sys.stdin.readline  # 빠른 입력

N, M = map(int, q_input().split())  # 입력 : 사람, 파티 수

# 입력 : 진실을 아는 사람
know_true = [False for _ in range(N + 1)]
for index in list(map(int, q_input().split()))[1:]:
    know_true[index] = True

# 입력 : 파티 참석 인원 정보
parties = []
for _ in range(M):
    parties.append(list(map(int, q_input().split()))[1:])


# 진실을 새롭게 알게 된 사람이 있는지를 알려주는 함수
# 즉, return True : 진실을 알게 된 사람이 있다
def update():
    changed = False

    for party in parties:
        flag = False
        for person in party:
            # 특정 파티에서 진실을 아는 사람이 있는 경우
            if know_true[person]:
                # flag, changed 갱신 후 break
                flag = True
                changed = True
                break

        # flag 변수가 활성화 된 경우
        if flag:
            # 해당 파티 인원 모두 진실을 알도록 갱신
            for person in party:
                know_true[person] = True

            # 중복 탐색을 방지하기 위해
            # 갱신이 끝나면 해당 파티 정보 삭제
            parties.remove(party)

    return changed


while True:
    # update()를 더 이상 수행하지 않아도 되는 경우 while 탈출
    if update() is not True:
        break

# 정답 출력
count = len(parties)
print(count)
