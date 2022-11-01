// 설명 링크 : https://moon-gd.tistory.com/76
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

typedef struct node {
	int row;
	int col;
	int day;
}node;

// queue
node queue[MAX * MAX];
int front = 0, rear = 0;

void enque(int row_pos, int col_pos, int count);
node deque();

// 방향 배열
int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };

// 토마토 상자 정보
int tomatoes[MAX][MAX];
int col, row;

// 방문 배열
int visited[MAX][MAX];

// 전역 변수
int i, j;

int main() {
	scanf("%d %d", &col, &row);

	int empty_space = 0;
	int colored_space = 0;

	int day = 0;

	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			scanf("%d", &tomatoes[i][j]);

			// 빈 칸인 경우, space_size - 1
			if (tomatoes[i][j] == -1) {
				empty_space++;
			}
			// 토마토가 있는 경우
			else if (tomatoes[i][j]) {
				visited[i][j] = 1;
				colored_space++;
				enque(i, j, 0);
			}
		}
	}

	while (front != rear) {
		node temp = deque();

		int cur_row = temp.row;
		int cur_col = temp.col;
		int cur_day = temp.day;

		for (i = 0; i < 4; i++) {
			int new_row = cur_row + dir_row[i];
			int new_col = cur_col + dir_col[i];

			// continue : 허용 row 범위를 벗어난 경우
			if (new_row <= 0 || new_row > row) {
				continue;
			}

			// continue : 허용 col 범위를 벗어난 경우
			if (new_col <= 0 || new_col > col) {
				continue;
			}

			// continue : 빈 칸인 경우
			if (tomatoes[new_row][new_col] == -1) {
				continue;
			}

			// continue : 이미 방문한 곳인 경우
			if (visited[new_row][new_col]) {
				continue;
			}
			
			visited[new_row][new_col] = 1;
			colored_space++;
			day = cur_day + 1;
			enque(new_row, new_col, day);
		}
	}

	// 모든 칸에 대해서 작업이 이루어진 경우
	if (colored_space + empty_space == row * col) {
		// 익은 토마토가 없는 경우
		// 즉, 애초에 상자가 비어있는 경우
		if (colored_space == 0) {
			printf("0");
		}
		// 일반적인 경우
		else {
			printf("%d", day);
		}
	}
	// 도달하지 못한 칸이 있는 경우
	else {
		printf("-1");
	}

	return 0;
}

// 큐 삽입 함수
void enque(int row_pos, int col_pos, int count) {
	node temp = { row_pos, col_pos, count };

	queue[++rear] = temp;
}

// 큐 추출 함수
node deque() {
	return queue[++front];
}