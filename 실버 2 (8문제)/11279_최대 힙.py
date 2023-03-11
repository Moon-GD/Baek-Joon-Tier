# 설명 링크 : https://moon-gd.tistory.com/142
import sys


class Heap:
    def __init__(self):
        self.list = [-1, ]
        self.size = 0

    def add(self, number):
        # create : new node
        self.list.append(number)

        # update : size of heap
        self.size += 1

        # initialize : index of new node
        new_index = self.size

        # heapify
        while new_index > 1:
            # new_node's key is bigger than parent node's key
            if self.list[new_index] > self.list[new_index // 2]:
                # exchange each other
                self.list[new_index], self.list[new_index // 2] = self.list[new_index // 2], self.list[new_index]

                # update : new index
                new_index //= 2
            else:
                break

    def delete(self):
        # if empty heap
        if self.size == 0:
            return 0

        # initialize : save root key to return later
        root_key = self.list[1]

        # update : exchange root node and last node
        self.list[1], self.list[self.size] = self.list[self.size], self.list[1]

        # update : reduce size by 1
        self.size -= 1

        # delete : previous root node
        del self.list[-1]

        # initialize : index
        index = 1

        # heapify
        while index <= self.size:
            # left/right child nodes exist
            if index * 2 + 1 <= self.size:
                # break : heapify is done
                if self.list[index] >= self.list[index * 2] and self.list[index] >= self.list[index * 2 + 1]:
                    break
                else:
                    # left child node has the biggest key
                    if self.list[index * 2] >= self.list[index] and self.list[index * 2] >= self.list[index * 2 + 1]:
                        # update : exchange left child and current node
                        self.list[index], self.list[index * 2] = self.list[index * 2], self.list[index]

                        # update : multiply index by 2
                        index *= 2

                    # right child node has the biggest key
                    elif self.list[index * 2 + 1] >= self.list[index] and self.list[index * 2 + 1] >= self.list[index * 2]:
                        # update : exchange right child and current node
                        self.list[index], self.list[index * 2 + 1] = self.list[index * 2 + 1], self.list[index]

                        # update : multiply index by 2 and plus 1
                        index = index * 2 + 1

            # only left child node exists
            elif index * 2 <= self.size:
                # left child node's key is bigger
                if self.list[index * 2] >= self.list[index]:
                    # update : swap child node's key and current node's
                    self.list[index], self.list[index * 2] = self.list[index * 2], self.list[index]

                    # update : multiply index by 2
                    index *= 2

                # current node's key is bigger
                else:
                    break

            # break : no child node exists
            else:
                break

        return root_key


# to get input faster
q_input = sys.stdin.readline

# input : number of operations
N = int(q_input())

# declare : heap
heap = Heap()

for i in range(N):
    # input : operation
    operation = int(q_input())

    # add
    if operation:
        heap.add(operation)
    # delete
    else:
        print(heap.delete())
