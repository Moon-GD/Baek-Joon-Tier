# 참고 링크 : https://moon-gd.tistory.com/34
N = int(input())

for _ in range(N):
    A, B = input().split(' ')
    if sorted(A) == sorted(B):
        print('{} & {} are anagrams.'.format(A, B))
    else:
        print('{} & {} are NOT anagrams.'.format(A, B))