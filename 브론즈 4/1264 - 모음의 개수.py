to_find = ['a', 'e', 'i', 'o', 'u']

while True:
    sum = 0
    sentence = input().lower()

    if(sentence == '#'):
        break

    for c in to_find:
        sum += sentence.count(c)
    print(sum)
