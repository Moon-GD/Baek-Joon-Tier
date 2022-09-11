// ���� ��ũ : https://moon-gd.tistory.com/72
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 301

// �ʿ��� ���� ����
int dir_X[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dir_Y[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int size = 0;  // ü���� ũ��
int cur_x, cur_y;  // ���� ��ġ ��ǥ
int goal_x, goal_y;  // ��ǥ ��ġ ��ǥ
int visited[MAX_SIZE][MAX_SIZE];  // �湮 �迭
int move_count = 0;

// Queue �迭�� ���� ����ü
typedef struct node {
	int x;
	int y;
	int count;
}node;

node queue[MAX_SIZE * MAX_SIZE + 1];
int front = 0, rear = 0;  // Queue �ε��� ����

// �ʿ� �Լ� ����
void initialize(int);  // �ʱ�ȭ �Լ�
void dfs();  // �ʺ� �켱 Ž�� �Լ�
void enque(int x, int y, int count);  // Queue ���� �Լ�
node deque();  // Queue ���� �Լ�

int main() {
	int test_num = 0;
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		scanf("%d %d %d %d %d", &size, &cur_x, &cur_y, &goal_x, &goal_y);  // �ʿ� ���� �Է� �ޱ�

		// �ʱ�ȭ
		initialize(size);

		enque(cur_x, cur_y, 0);
		dfs();
		printf("%d\n", move_count);
	}

	return 0;
}

void initialize(int length) {
	// �ʱ�ȭ ��� : 
	// �� �湮 �迭
	// �� ������ Ƚ�� = 0
	// �� queue �ε��� ����

	int i, j;

	// �� �湮 �迭 �ʱ�ȭ
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			visited[i][j] = 0;
		}
	}

	// �� ������ Ƚ�� = 0 ���� ����
	move_count = 0;

	// �� queue �ε��� ���� �ʱ�ȭ
	front = 0;
	rear = 0;
}

void dfs() {
	while (1) {
		node temp = deque();
		int x = temp.x;
		int y = temp.y;
		int count = temp.count;

		// �������� ������ ���
		if (x == goal_x && y == goal_y) {
			move_count = count;
			return;
		}

		// �������� ������ 8���� ���� ��ȸ
		for (int i = 0; i < 8; i++) {
			int new_x = x + dir_X[i];
			int new_y = y + dir_Y[i];

			// X ��� ������ ��� ��� 1
			if (new_x < 0 || new_x >= size) {
				continue;
			}

			// Y ��� ������ ��� ��� 2
			if (new_y < 0 || new_y >= size) {
				continue;
			}

			// �̹� �湮�� ���� ���
			if (visited[new_x][new_y]) {
				continue;
			}

			// ���� ���� ���׿� �ش����� �ʴ� ��� Queue�� ����
			enque(new_x, new_y, count + 1);

			// Enque�� ��ǥ �湮 �迭�� ���
			visited[new_x][new_y] = 1;
		}
	}
}

void enque(int x, int y, int count) {
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].count = count;
	rear++;
}

node deque() {
	return queue[front++];
}