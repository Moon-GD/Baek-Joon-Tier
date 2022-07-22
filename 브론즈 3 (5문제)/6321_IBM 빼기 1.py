size = int(input())

for i in range(1, size + 1):
    computer = input()
    print('String #{}'.format(i))
    for c in computer:
        if c == 'Z':
            print('A', end='')
        else:
            print(chr(ord(c) + 1), end='')

    print('')
    print('')