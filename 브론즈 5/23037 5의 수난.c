#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 다섯 제곱 계산해주는 함수
int five(int n);

int main() {
	int sum = 0;
	int n;
	scanf("%d", &n);  // 입력 받기


	while (n) {
		sum += five(n % 10);
		n /= 10;
	}

	printf("%d", sum);

	return 0;
}

// 다섯 제곱 계산해주는 함수
int five(int n) {
	int multi = 1;

	// 반복문을 다섯 번 돌면서 n을 곱한다.
	for (int i = 1; i <= 5; i++) {
		multi *= n;
	}

	return multi;
}