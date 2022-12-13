// ���� ��ũ : https://moon-gd.tistory.com/38
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

int dirRow[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dirCol[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
char road[MAX][MAX];
int row, col;

int main() {

	while (1) {
		// ��� �� �Է¹ޱ�
		scanf("%d %d", &row, &col);

		// �� �� 0�� �ԷµǸ� ����
		if (row + col == 0) {
			break;
		}
		
		for (int i = 0; i < row; i++) {
			scanf("%s", road[i]);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// ������ ��� continue
				if (road[i][j] == '*') {
					continue;
				}
				// ���ڰ� �ƴ� ���, �ֺ� ������ ���� Ȯ��
				int count = 0;
				for (int k = 0; k < 8; k++) {
					// ��ȿ ������ ��� ��� continue
					if (dirRow[k] + i < 0 || dirRow[k] + i >= row || dirCol[k] + j < 0 || dirCol[k] + j >= col) {
						continue;
					}

					// ��ȿ ���� ������ ���ڰ� ���� ��� count 1 ����
					if (road[i + dirRow[k]][j + dirCol[k]] == '*') {
						count++;
					}
				}
				road[i][j] = '0' + count;
			}
		}

		for (int i = 0; i < row; i++) {
			printf("%s\n", road[i]);
		}
	}


	return 0;
}