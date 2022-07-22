size = int(input())
numbers = [int(input()) for _ in range(size)]

for number in sorted(numbers):
    print(number)