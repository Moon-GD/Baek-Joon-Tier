// 참고 링크 : https://moon-gd.tistory.com/30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 두 정수를 바꿔주는 함수
void swap(long long* a, long long* b);

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);

	// a가 더 큰 입력으로 들어오는 경우, a와 b를 바꾸어준다.
	if (a > b) {
		swap(&a, &b);
	}

	printf("%lld", (a + b) * (b - a + 1) / 2);

	return 0;
}

// 두 정수를 바꿔주는 함수
void swap(long long* a, long long* b) {
	long long temp = *a;
	*a = *b;
	*b = temp;
}