// ���� ��ũ : https://moon-gd.tistory.com/135
#define _CRT_SECURE_NO_WARNINGS
#define MAX 128
#include <stdio.h>

int squares[MAX][MAX];  // ���� ����
int visited[MAX][MAX];  // �湮 ����
int size = 0;

int blue_paper = 0;  // �Ķ��� ������
int white_paper = 0;  // �Ͼ�� ������

void solve();
int search(int start_row, int start_col, int cur_length);
int color(int start_row, int start_col, int cur_length);

int main() {
	// �Է� : ���� ����
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &squares[i][j]);
		}
	}

	solve();

	printf("%d\n", white_paper);
	printf("%d", blue_paper);

	return 0;
}

void solve() {
	int length = size;
	
	while (length) {
		for (int i = 0; i < size; i += length) {
			for (int j = 0; j < size; j += length) {
				// continue : �̹� �湮�� ���� ���
				if (visited[i][j]) {
					continue;
				}

				if (search(i, j, length)) {
					color(i, j, length) == 1 ? blue_paper++ : white_paper++;
				}
			}
		}
		length /= 2;
	}
}

int search(int start_row, int start_col, int cur_length) {
	int cur_color = squares[start_row][start_col];

	for (int i = start_row; i < start_row + cur_length; i++) {
		for (int j = start_col; j < start_col + cur_length; j++) {
			if (squares[i][j] != cur_color) {
				return 0;
			}
		}
	}

	return 1;
}

int color(int start_row, int start_col, int cur_length) {
	for (int i = start_row; i < start_row + cur_length; i++) {
		for (int j = start_col; j < start_col + cur_length; j++) {
			visited[i][j] = 1;
		}
	}

	return squares[start_row][start_col];
}