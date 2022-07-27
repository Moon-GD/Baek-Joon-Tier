// 참고 링크 : https://moon-gd.tistory.com/40
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int first[MAX][MAX];
int second[MAX][MAX];

int sum(int, int, int);

int main() {
	int row1, col1, row2, col2;

	scanf("%d %d", &row1, &col1);

	// 첫 번째 행렬 입력받기
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			scanf("%d", &first[i][j]);
		}
	}

	// 두 번째 행렬 입력받기
	scanf("%d %d", &row2, &col2);
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			scanf("%d", &second[i][j]);
		}
	}

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			printf("%d ", sum(i, j, row2));
		}
		putchar('\n');
	}

	return 0;
}

int sum(int first_info, int second_info, int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += (first[first_info][i] * second[i][second_info]);
	}

	return sum;
}