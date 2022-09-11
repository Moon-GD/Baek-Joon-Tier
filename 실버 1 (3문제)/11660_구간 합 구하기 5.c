// 설명 링크 : https://moon-gd.tistory.com/73
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1025

int number;
int sums[MAX][MAX];  // 누적 합

int main() {
	int size = 0, times = 0;
	scanf("%d %d", &size, &times);

	int i, j;
	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			scanf("%d", &number);

			// 누적 합 정보 저장
			sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + number;
		}
	}

	int start_row, start_col, end_row, end_col;

	for (i = 1; i <= times; i++) {
		scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

		printf("%d\n", sums[end_row][end_col] - sums[start_row - 1][end_col] - sums[end_row][start_col - 1] + sums[start_row - 1][start_col - 1]);
	}

	return 0;
}