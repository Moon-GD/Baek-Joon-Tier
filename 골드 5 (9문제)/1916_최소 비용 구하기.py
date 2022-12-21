# 설명 링크 : https://moon-gd.tistory.com/140
import sys

q_input = sys.stdin.readline  # for faster input

# get : num of city and bus, respectively
city = int(q_input())
bus = int(q_input())

# declare : maximum distance
MAX_DISTANCE = 999999999

# declare : list for recording distance between cities
cities = [[MAX_DISTANCE for _ in range(city + 1)] for _ in range(city + 1)]

# get : distance info's
for _ in range(bus):
    start, end, distance = map(int, q_input().split())

    # update : distance from start to end
    if cities[start][end] == MAX_DISTANCE:
        cities[start][end] = distance
    else:
        cities[start][end] = min(cities[start][end], distance)

# get : target_start place & target_end place
target_start, target_end = map(int, q_input().split())

# declare : distance list for dijkstra
distance = [MAX_DISTANCE for _ in range(city + 1)]

# initialize : distance of target_start
distance[target_start] = 0

# declare : list that checks if vertex is visited
visited = [False for _ in range(city + 1)]

# declare : start vertex for dijkstra
start_city = city + 1

# search : dijkstra
for i in range(1, city + 1):
    # initialize : min_distance to be MAX_DISTANCE (9,9999,9999)
    min_distance = MAX_DISTANCE

    # search Ⅱ : find start_vertex that can be touched from target_start
    for j in range(1, city + 1):
        if visited[j] is not True and distance[j] < min_distance:
            start_city = j
            min_distance = distance[j]

    # update : visited info of start_city
    visited[start_city] = True

    # update : distance from start_city
    for j in range(1, city + 1):
        if cities[start_city][j] != MAX_DISTANCE and distance[j] > distance[start_city] + cities[start_city][j]:
            distance[j] = distance[start_city] + cities[start_city][j]

# result : print distance from target_start to target_end
print(distance[target_end])
