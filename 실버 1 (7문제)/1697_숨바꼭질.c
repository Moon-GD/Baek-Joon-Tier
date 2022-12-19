#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 150000

// declare : structure for queue
typedef struct node {
	int cur_pos;
	int count;
}node;

// declare : queue, size of MAX
node queue[MAX];

// declare : queue variables
int front = -1, rear = -1;

// declare : queue functions
void enque(int cur_pos, int count);
node deque();

// declare : array recording distances
int distance[MAX];

// declare : N - my position, K - brother position
int N, K;

// declare : function that returns min(a, b)
int get_min(int a, int b);

int main() {
	// get input : N, K
	scanf("%d %d", &N, &K);

	// brother is to the left of me
	if (N >= K) {
		printf("%d", N - K);
	}
	// brother is to the right of me
	else {
		// initialize : queue
		enque(N, 0);

		// bfs
		while (front != rear) {
			// get : current node
			node temp = deque();

			// get : current pos, count
			int new_pos = temp.cur_pos;
			int new_count = temp.count;

			// continue : out of validate coordinates
			if (new_pos >= MAX || new_pos < 0) {
				continue;
			}

			if (new_pos == K) {
				break;
			}
				
			// if pos = new_pos - 1 is not visited
			if (distance[new_pos - 1] == 0) {
				// update : new_pos - 1
				distance[new_pos - 1] = new_count + 1;

				// add : node of new_pos - 1, new_count + 1
				enque(new_pos - 1, new_count + 1);
			}

			// if pos = new_pos + 1 is not visited
			if (distance[new_pos + 1] == 0) {
				// update : new_pos + 1
				distance[new_pos + 1] = new_count + 1;

				// add : node of new_pos + 1, new_count + 1
				enque(new_pos + 1, new_count + 1);
			}

			// if pos = new_pos * 2 is not visited
			if (distance[new_pos * 2] == 0) {
				// update : new_pos * 2
				distance[new_pos * 2] = new_count + 1;

				// add : node of new_pos * 2, new_count + 1
				enque(new_pos * 2, new_count + 1);
			}
		}

		printf("%d", distance[K]);
	}

	return 0;
}

void enque(int cur_pos, int count) {
	// update : rear
	rear = (rear + 1) % MAX;

	// create : new node
	node temp;
	temp.cur_pos = cur_pos;
	temp.count = count;

	// enque
	queue[rear] = temp;
}

node deque() {
	// update : front
	front = (front + 1) % MAX;	

	// deque
	return queue[front];
}

// return min(a, b)
int get_min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}