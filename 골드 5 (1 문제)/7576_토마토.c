// ���� ��ũ : https://moon-gd.tistory.com/76
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

// ���� �迭
int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };

// �丶�� ���� ����
int tomatoes[MAX][MAX];
int col, row;

// �湮 �迭
int visited[MAX][MAX];

// ���� ����
int i, j;

int main() {
	scanf("%d %d", &col, &row);

	int empty_space = 0;
	int colored_space = 0;

	int day = 0;

	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			scanf("%d", &tomatoes[i][j]);

			// �� ĭ�� ���, space_size - 1
			if (tomatoes[i][j] == -1) {
				empty_space++;
			}
			// �丶�䰡 �ִ� ���
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

			// continue : ��� row ������ ��� ���
			if (new_row <= 0 || new_row > row) {
				continue;
			}

			// continue : ��� col ������ ��� ���
			if (new_col <= 0 || new_col > col) {
				continue;
			}

			// continue : �� ĭ�� ���
			if (tomatoes[new_row][new_col] == -1) {
				continue;
			}

			// continue : �̹� �湮�� ���� ���
			if (visited[new_row][new_col]) {
				continue;
			}
			
			visited[new_row][new_col] = 1;
			colored_space++;
			day = cur_day + 1;
			enque(new_row, new_col, day);
		}
	}

	// ��� ĭ�� ���ؼ� �۾��� �̷���� ���
	if (colored_space + empty_space == row * col) {
		// ���� �丶�䰡 ���� ���
		// ��, ���ʿ� ���ڰ� ����ִ� ���
		if (colored_space == 0) {
			printf("0");
		}
		// �Ϲ����� ���
		else {
			printf("%d", day);
		}
	}
	// �������� ���� ĭ�� �ִ� ���
	else {
		printf("-1");
	}

	return 0;
}

// ť ���� �Լ�
void enque(int row_pos, int col_pos, int count) {
	node temp = { row_pos, col_pos, count };

	queue[++rear] = temp;
}

// ť ���� �Լ�
node deque() {
	return queue[++front];
}