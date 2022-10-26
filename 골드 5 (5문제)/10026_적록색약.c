// ���� ��ũ : https://moon-gd.tistory.com/95
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100 + 1
#define QUEUE_SIZE 10000
#include <stdio.h>

// �׸�	���� ������ ����ü ����
typedef struct node {
	int isVisited;
	char color;
	char type;
}node;
node grids[MAX][MAX] = { 0 };

// BFS Ž���� ���� Queue ����
typedef struct pos_node {
	int x;
	int y;
}pos_node;
pos_node queue[QUEUE_SIZE];

// Queue ���� ����
int front = 0, rear = 0;

// Queue ���� �Լ� ����
void push(int i, int j);
pos_node pop();

// ���� �迭 ����
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

// BFS �Լ�
void BFS();
void BFS_type();

// �׸� ũ��
int size;

// �ݺ��� �ӽ� ���� ����
int i, j, k;
char temp_c;

// ���� ����
int goal = 0;
int goal_type = 0;

int main() {
	// �׸� ũ�� �Է�
	scanf("%d", &size);

	// ���� ó��
	scanf("%c", &temp_c);

	// �׸� ���� �Է�
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%c", &grids[i][j].color);

			// ���ϻ��� ó��
			if (grids[i][j].color == 'B') {
				grids[i][j].type = 'X';
			}
			else {
				grids[i][j].type = 'Y';
			}
		}
		scanf("%c", &temp_c);
	}

	// BFS Ž��
	BFS();

	// BFS_type Ž��
	BFS_type();
	
	printf("%d %d", goal, goal_type);

	return 0;
}

void push(int i, int j) {
	pos_node temp_pos_node = { i, j };
	rear = (rear + 1) % QUEUE_SIZE;
	queue[rear] = temp_pos_node;
}

pos_node pop() {
	front = (front + 1) % (QUEUE_SIZE);
	return queue[front];
}

void BFS() {
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// Continue : �湮�� ĭ
			if (grids[i][j].isVisited) {
				continue;
			}
			// �湮���� ���� ���
			else {
				// ���� ���� ����
				char start_color = grids[i][j].color;

				// ť �ε��� �ʱ�ȭ
				front = rear = 0;

				push(i, j);
				grids[i][j].isVisited = 1;
				goal += 1;

				// ť�� �� ������
				while (front != rear) {
					pos_node pos = pop();

					for (k = 0; k < 4; k++) {
						int new_x = pos.x + dir_x[k];
						int new_y = pos.y + dir_y[k];

						// Continue : X ��� ������ ��� ���
						if (0 > new_x || new_x >= size) {
							continue;
						}

						// Continue : Y ��� ������ ��� ���
						if (0 > new_y || new_y >= size) {
							continue;
						}
						
						// Continue : �̹� �湮�� ���
						if (grids[new_x][new_y].isVisited) {
							continue;
						}

						if (grids[new_x][new_y].color == start_color) {
							push(new_x, new_y);
							grids[new_x][new_y].isVisited = 1;
						}
					}
				}
			}
		}
	}


}

void BFS_type() {
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// Continue : �湮�� ĭ
			// �� ���� isVisited = 0�� ���� �湮�� ĭ
			if (grids[i][j].isVisited == 0) {
				continue;
			}
			// �湮���� ���� ���
			else {
				// ���� ���� ����
				char start_type = grids[i][j].type;

				// ť �ε��� �ʱ�ȭ
				front = rear = 0;

				push(i, j);
				grids[i][j].isVisited = 0;
				goal_type += 1;

				// ť�� �� ������
				while (front != rear) {
					pos_node pos = pop();

					for (k = 0; k < 4; k++) {
						int new_x = pos.x + dir_x[k];
						int new_y = pos.y + dir_y[k];

						// Continue : X ��� ������ ��� ���
						if (0 > new_x || new_x >= size) {
							continue;
						}

						// Continue : Y ��� ������ ��� ���
						if (0 > new_y || new_y >= size) {
							continue;
						}

						// Continue : �̹� �湮�� ���
						if (grids[new_x][new_y].isVisited == 0) {
							continue;
						}

						if (grids[new_x][new_y].type == start_type) {
							push(new_x, new_y);
							grids[new_x][new_y].isVisited = 0;
						}
					}
				}
			}
		}
	}
}