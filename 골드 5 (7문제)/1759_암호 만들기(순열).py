# 설명 링크 : https://moon-gd.tistory.com/97
from itertools import combinations
import sys
q_input = sys.stdin.readline  # 빠른 입력

# code_len : 암호 길이
# total_len : 알파벳 개수
code_len, total_len = map(int, q_input().split())

# 알파벳 종류 입력 받고 오름차순 정렬
spells = list(q_input().split())
spells.sort()

# 암호 리스트
code = []


def code_validity():
    consonant = 0  # 자음
    collection = 0  # 모음
    
    # 자음, 모음 개수 확인
    for c in code:
        if c in ['a', 'e', 'i', 'o', 'u']:
            collection += 1
        else:
            consonant += 1

    # Return True : 모음, 자음 개수가 충분한 경우
    if collection >= 1 and consonant >= 2:
        return True
    # Return False : 모음, 자음 개수가 충분하지 않은 경우 
    else:
        return False


def combination(code_len, spells):
    return combinations(spells, code_len)


code_list = list(combination(code_len, spells))

for c in code_list:
    code = c
    if code_validity():
        print("".join(code))