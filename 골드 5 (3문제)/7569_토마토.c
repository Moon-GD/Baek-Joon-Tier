// ���� ��ũ : https://moon-gd.tistory.com/80
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

typedef struct node {
	int x;
	int y;
	int z;
	int day;
}node;
node queue[MAX * MAX * MAX];

// ť ���� �Լ�
int front = 0, rear = 0;
void enque(int, int, int, int);
node deque();

int tomatoes[MAX][MAX][MAX];  // �丶�� ���� �迭
int visited[MAX][MAX][MAX];  // �湮 �迭

// �̵� ���� ���� �迭
int dir_x[6] = { 0, 0, 0, 1, 0, -1 };
int dir_y[6] = { 0, 0, -1, 0, 1, 0 };
int dir_z[6] = { 1, -1, 0, 0, 0, 0 };

int main() {
	// �ݺ��� ��ȸ�� ���� �ӽ� ���� ����
	int i, j, k;

	// �丶�� ���� ũ�� Ȯ��
	int x_size, y_size, z_size;
	scanf("%d %d %d", &x_size, &y_size, &z_size);

	// ���� ���� üũ�� ���� ����
	int total_size, colored_size = 0, empty_size = 0;
	total_size = x_size * y_size * z_size;

	// ���� ���� �Է� �ޱ�
	for (k = 0; k < z_size; k++) {
		for (j = 0; j < y_size; j++) {
			for (i = 0; i < x_size; i++) {
				scanf("%d", &tomatoes[i][j][k]);

				// �丶�䰡 �ִ� ĭ�� ���
				if (tomatoes[i][j][k] == 1) {
					// ť�� �־��ְ� �湮 ���� üũ
					enque(i, j, k, 0);
					visited[i][j][k] = 1;
				}
				// �� ĭ�� ���
				else if (tomatoes[i][j][k] == -1) {
					// �� ���� ++
					empty_size++;
				}
			}
		}
	}

	// ��ĥ ���� ++
	colored_size = rear;

	while (front != rear) {
		// ť���� ���� �丶�� ���� �ϳ� ����
		node temp = deque();

		int cur_x = temp.x;
		int cur_y = temp.y;
		int cur_z = temp.z;
		int cur_day = temp.day;

		for (i = 0; i < 6; i++) {
			int new_x = cur_x + dir_x[i];
			int new_y = cur_y + dir_y[i];
			int new_z = cur_z + dir_z[i];

			// X ���� ��ȿ�� �˻�
			if (new_x < 0 || new_x >= x_size) {
				continue;
			}

			// Y ���� ��ȿ�� �˻�
			if (new_y < 0 || new_y >= y_size) {
				continue;
			}

			// Z ���� ��ȿ�� �˻�
			if (new_z < 0 || new_z >= z_size) {
				continue;
			}

			// �̹� �湮�� ���� ���
			if (visited[new_x][new_y][new_z]) {
				continue;
			}

			// �� ĭ�� ���
			if (tomatoes[new_x][new_y][new_z] == -1) {
				continue;
			}

			// ���� �ݷʿ� ��� �ش����� �ʴ� ���
			// ��, ���� ���� ���ο� �丶�並 ã���� ���
			enque(new_x, new_y, new_z, cur_day + 1);

			// ��ĥ ���� �߰� + �湮 ���� üũ
			colored_size++;
			visited[new_x][new_y][new_z] = 1;
		}
	}

	if (colored_size + empty_size == total_size) {
		if (colored_size) {
			printf("%d", queue[rear - 1].day);
		}
		else {
			printf("0");
		}
	}
	else {
		printf("-1");
	}

	return 0;
}

void enque(int x, int y, int z, int day) {
	node temp = { x, y, z, day };
	queue[rear++] = temp;
}

node deque() {
	return queue[front++];
}