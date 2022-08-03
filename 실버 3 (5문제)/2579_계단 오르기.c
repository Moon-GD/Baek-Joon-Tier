// 참고 링크 : https://moon-gd.tistory.com/55
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 301
#define get_max(a, b) a > b ? a : b

int scores[MAX];
int stairs[MAX];

int main() {
	int size;
	scanf("%d", &size);

	// 점수 입력 받기
	for (int i = 1; i <= size; i++) {
		scanf("%d", &scores[i]);
	}

	stairs[1] = scores[1];
	stairs[2] = scores[1] + scores[2];

	for (int i = 3; i <= size; i++) {
		stairs[i] = get_max(stairs[i - 2] + scores[i], stairs[i - 3] + scores[i - 1] + scores[i]);
	}

	printf("%d", stairs[size]);

	return 0;
}