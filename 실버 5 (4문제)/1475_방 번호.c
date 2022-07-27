// 참고 링크 : https://moon-gd.tistory.com/39
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int number[10] = { 0 };
	int N = 0, max = 0;

	scanf("%d", &N);

	while (N) {
		number[N % 10]++;
		N /= 10;
	}

	if ((number[6] + number[9]) % 2 == 1) {
		number[6] = (number[6] + number[9] + 1) / 2;
	}
	else {
		number[6] = (number[6] + number[9]) / 2;
	}

	for (int i = 0; i < 9; i++) {
		if (max < number[i]) {
			max = number[i];
		}
	}

	printf("%d", max);

	return 0;
}