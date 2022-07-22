melody, avg = map(int, input().split())
avg = avg - 0.999999

print(int(melody * avg) + 1)