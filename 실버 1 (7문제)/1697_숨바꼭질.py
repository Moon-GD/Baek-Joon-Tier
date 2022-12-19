import collections

# declare : queue
queue = collections.deque()

# N : my position
# K : brother's position
N, K = map(int, input().split())

# brother is to the left of me
if N >= K:
    print(N - K)
# brother is to the right of me
else:
    # declare : max number can be used in this algorithm
    MAX = 150000

    # declare : list that contains distance from N
    distance = [0 for i in range(MAX)]

    # initialize : queue
    queue.append([N, 0])

    # iterates the loop until queue is not empty
    while queue:
        # get : current position, current count from N
        cur_position, cur_count = queue.popleft()

        if cur_position == K:
            distance[cur_position] = cur_count
            break

        # continue : cur_position is out of valid coordinates
        if cur_position < 0 or cur_position >= MAX:
            continue

        # if pos(cur_position - 1) is not visited
        if cur_position - 1 >= 0 and distance[cur_position - 1] == 0:
            # update pos(cur_position - 1)
            distance[cur_position - 1] = cur_count + 1

            # add : add list of [cur_position - 1, cur_count + 1] to queue
            queue.append([cur_position - 1, cur_count + 1])

        # if pos(cur_position + 1) is not visited
        if cur_position + 1 < MAX and distance[cur_position + 1] == 0:
            # update pos(cur_position + 1)
            distance[cur_position + 1] = cur_count + 1

            # add : add list of [cur_position + 1, cur_count + 1] to queue
            queue.append([cur_position + 1, cur_count + 1])

        # if pos(cur_position * 2) is not visited
        if cur_position * 2 < MAX and distance[cur_position * 2] == 0:
            # update pos(cur_position * 2)
            distance[cur_position * 2] = cur_count + 1

            # add : add list of [cur_position * 2, cur_count + 1] to queue
            queue.append([cur_position * 2, cur_count + 1])

    print(distance[K])
