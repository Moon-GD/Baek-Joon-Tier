// 설명 링크 : https://moon-gd.tistory.com/141
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int dp[MAX];

int main() {
	// declare : size of the given rectangle
	int size = 0;

	// input : get size of the given rectangle
	scanf("%d", &size);

	// initialize : dp
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= size; i++) {
		// initialize : i-th dp
		dp[i] = dp[i - 1] + dp[i - 2];

		// update : i-th dp because value can be overflowed
		dp[i] = dp[i] % 10007;
	}

	// result
	printf("%d", dp[size]);

	return 0;
}