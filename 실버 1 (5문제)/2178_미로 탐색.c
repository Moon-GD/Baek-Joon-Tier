// ���� ��ũ : https://moon-gd.tistory.com/74
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

char maze[MAX][MAX];
int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };
int visited[MAX][MAX];

typedef struct node {
	int row;
	int col;
	int count;
}node;

node queue[MAX * MAX];
int front = 0, rear = 0;

void enque(int r, int c, int count);
node deque();

int main() {
	int row, col;
	int i, j;
	char temp_c;

	// �Է� �ޱ�
	scanf("%d %d", &row, &col);
	scanf("%c", &temp_c);
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			scanf("%c", &maze[i][j]);
		}
		scanf("%c", &temp_c);
	}

	// (1, 1) ť�� �ְ� �湮 ǥ�����ֱ�
	enque(1, 1, 1);
	visited[1][1] = 1;
	
	while (1) {
		node temp = deque();
		int cur_row = temp.row;
		int cur_col = temp.col;
		int cur_count = temp.count;

		// �������� ������ ���
		if (cur_row == row && cur_col == col) {
			printf("%d", cur_count);
			break;
		}

		for (i = 0; i < 4; i++) {
			int new_row = cur_row + dir_row[i];
			int new_col = cur_col + dir_col[i];

			// row ��� ������ ��� ���
			if (new_row <= 0 || new_row > row) {
				continue;
			}

			// col ��� ������ ��� ���
			if (new_col <= 0 || new_col > col) {
				continue;
			}

			// ������ �� ���� ���
			if (maze[new_row][new_col] == '0') {
				continue;
			}

			// �̹� �湮�� ���� ���
			if (visited[new_row][new_col]) {
				continue;
			}

			// ���� �ݷʵ鿡 �ش����� �ʴ� ���
			// queue�� �ְ� �湮 ǥ�����ֱ�
			enque(new_row, new_col, cur_count + 1);
			visited[new_row][new_col] = 1;
		}
	}

	return 0;
}

void enque(int r, int c, int count) {
	node temp = { r, c, count };
	queue[rear++] = temp;
}

node deque() {
	return queue[front++];
}