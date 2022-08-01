// 참고 링크 : https://moon-gd.tistory.com/49
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001

int numbers[MAX] = { 0, 0, 1, 1 };

int main() {
	int size = 0;
	scanf("%d", &size);

	// dp 계산
	for (int i = 4; i <= size; i++) {
		// 우선 i - 1 번째 값 + 1 을 저장
		numbers[i] = numbers[i - 1] + 1;

		// 2로 나누어지는 경우 확인
		if (i % 2 == 0 && numbers[i / 2]) {
			numbers[i] = numbers[i] < numbers[i / 2] + 1 ? numbers[i] : numbers[i / 2] + 1;
		}

		// 3으로 나누어지는 경우 확인
		if (i % 3 == 0 && numbers[i / 3]) {
			numbers[i] = numbers[i] < numbers[i / 3] + 1 ? numbers[i] : numbers[i / 3] + 1;
		}
	}

	printf("%d", numbers[size]);

	return 0;
}