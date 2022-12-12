// 설명 링크 : https://moon-gd.tistory.com/100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define QUEUE_SIZE 64

int row_size, col_size;
int map[MAX][MAX];

int zero_count, one_count, two_count;
int max = 0;

int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1};

typedef struct node {
	int row;
	int col;
}node;
node queue[QUEUE_SIZE];
node two_locations[QUEUE_SIZE];
int front = 0, rear = 0;

void enque(int, int);
node deque();

void bfs();

void choose(int depth);

int main() {
	// 입력
	scanf("%d %d", &row_size, &col_size);
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				zero_count++;
			}
			else if (map[i][j] == 1) {
				one_count++;
			}
			else {
				node temp = { i, j };
				two_locations[two_count] = temp;
				two_count++;
			}
		}
	}

	choose(0);

	printf("%d", max);

	return 0;
}

void enque(int row, int col) {
	node temp = { row, col };
	queue[rear] = temp;
	rear = (rear + 1) % QUEUE_SIZE;
}

node deque() {
	front = front % QUEUE_SIZE;
	return queue[front++];
}

void bfs() {
	int zero = zero_count, one = one_count + 3, two = two_count;
	rear = two_count;
	
	int copy_map[MAX][MAX] = { 0 };
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			copy_map[i][j] = map[i][j];
		}
	}

	front = 0, rear = 0;
	for (int i = 0; i < two_count; i++) {
		node temp = two_locations[i];
		enque(temp.row, temp.col);
	}

	while (rear != front) {
		node temp = deque();
		int cur_row = temp.row;
		int cur_col = temp.col;

		for (int i = 0; i < 4; i++) {
			int new_row = cur_row + dir_row[i];
			int new_col = cur_col + dir_col[i];

			// Continue : row 유효 범위를 벗어나는 경우
			if (new_row < 0 || new_row >= row_size) {
				continue;
			}

			// Continue : col 유효 범위를 벗어나는 경우
			if (new_col < 0 || new_col >= col_size) {
				continue;
			}

			// Continue : 빈 공간이 아닌 경우
			if (copy_map[new_row][new_col]) {
				continue;
			}

			two++;
			copy_map[new_row][new_col] = 2;
			enque(new_row, new_col);
		}
	}

	max = max > row_size * col_size - two - one ? max : row_size * col_size - two - one;
}

void choose(int depth) {
	if (depth == 3) {
		bfs();
		return;
	}
	else {
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					choose(depth + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}