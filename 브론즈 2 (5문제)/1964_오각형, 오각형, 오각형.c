// 참고 링크 :  https://moon-gd.tistory.com/29
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long dot = 0, N;

	scanf("%lld", &N);

	dot = (N + 1) * N / 2 + (N + 1) * (N + 1);
	dot %= 45678;
	printf("%lld", dot);

	return 0;
}