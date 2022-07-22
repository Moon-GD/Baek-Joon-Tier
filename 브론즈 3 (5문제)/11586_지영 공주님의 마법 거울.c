#define _CRT_SECURE_NO_WARNINGS
#define MAX 101
#include <stdio.h>
#include <string.h> // strlen

int main() {
	int size, num = 0;
	char mirror[MAX][MAX];

	// 거울 정보 입력 받기
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%s", mirror[i]);
	}

	// 조건 입력 받기
	scanf("%d", &num);

	// 그대로 출력
	if (num == 1) {
		for (int i = 0; i < size; i++) {
			printf("%s\n", mirror[i]);
		}
	}
	// 좌우 반전 출력
	else if (num == 2) {
		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j >= 0; j--) {
				printf("%c", mirror[i][j]);
			}
			putchar('\n');
		}
	}
	// 상하 반전
	else if (num == 3) {
		for (int i = size - 1; i >= 0; i--) {
			printf("%s\n", mirror[i]);
		}
	}

	return 0;
}