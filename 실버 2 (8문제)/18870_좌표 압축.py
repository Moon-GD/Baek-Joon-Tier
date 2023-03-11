# 설명 링크 : https://moon-gd.tistory.com/150
# get inputs
input_size = int(input())
coordinates = list(map(int, input().split()))

# sort
sorted_coordinates = sorted(set(coordinates))

# make index mapper using dictionary
index_mapper = {}
for index in range(len(sorted_coordinates)):
    index_mapper[sorted_coordinates[index]] = index

# print results
for number in coordinates:
    print(index_mapper[number], end=" ")
