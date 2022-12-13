// ���� ��ũ : https://moon-gd.tistory.com/37
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int vertex[MAX][2];
int count[MAX * 2 + 1];  // -10�� ~ 10������ �� 20�� 1���� ������ ��� ���� MAX * 2 + 1�� ����

// quick_sort �Լ�
// �� ��° ������ point = 0 -> x ��ǥ ���� ����, point = 1 -> y ��ǥ ���� ����
void quick_sort(int left, int right, int point);

// ��ǥ ��� �Լ�
void print_vertex(int size);

int main() {
	// �� �Է¹ޱ�
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d %d", &vertex[i][0], &vertex[i][1]);

		// count �迭�� �����ϴ� ������ x ��ǥ�� ��ġ�� ���� �ִ��� üũ�ϱ� ����.
		// x ��ǥ�� -10���� ��� 0��° �ε���, x ��ǥ�� 0 �� ���, 10����° �ε��� 1 ����
		count[vertex[i][0] + MAX]++;
	}

	// x ��ǥ ���� ����
	quick_sort(0, size - 1, 0);

	// count �迭�� Ȱ���ؼ� x ��ǥ�� ��ġ�� ���� �ִ��� ������ Ž��
	// ���� ���� ���, y ��ǥ �������� ����
	for (int i = 0; i < size; i++) {
		// ���� x ��ǥ�� ������ 1������ ���ٸ�, �ش� �������� y ��ǥ �������� quick_sort�� �� �� �� ���ݴϴ�.
		if (count[vertex[i][0] + MAX] > 1) {
			quick_sort(i, i + count[vertex[i][0] + MAX] - 1, 1);
			i += count[vertex[i][0] + MAX] - 1;
		}
	}

	// ���
	print_vertex(size);

	return 0;
}

void quick_sort(int left, int right, int point) {
	int L = left, R = right;
	int pivot = vertex[(left + right) / 2][point];

	do {
		while (vertex[L][point] < pivot) { L++; }
		while (vertex[R][point] > pivot) { R--; }

		if (L <= R) {
			// x ��ǥ �ٲٱ�
			int temp = vertex[L][0];
			vertex[L][0] = vertex[R][0];
			vertex[R][0] = temp;

			// y ��ǥ �ٲٱ�
			temp = vertex[L][1];
			vertex[L][1] = vertex[R][1];
			vertex[R][1] = temp;
			L++, R--;
		}
	} while (L <= R);


	if (left < R) {
		quick_sort(left, R, point);
	}

	if (L < right) {
		quick_sort(L, right, point);
	}
}

// ��ǥ ��� �Լ�
void print_vertex(int size) {
	for (int i = 0; i < size; i++) {
		printf("%d %d\n", vertex[i][0], vertex[i][1]);
	}
}