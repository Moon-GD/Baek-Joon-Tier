#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int sum = 0, time;

	// 입력 받으면서 총 시간 합 구하기
	for (int i = 0; i < 4; i++) {
		scanf("%d", &time);
		sum += time;
	}

	// 출력
	printf("%d\n%d", sum / 60, sum % 60);

	return 0;
}