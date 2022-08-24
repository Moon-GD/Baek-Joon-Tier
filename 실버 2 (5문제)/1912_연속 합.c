// 참고 링크 : https://moon-gd.tistory.com/66
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

// DP 배열
long long dp[MAX];

int main() {
	long long max = -1000;
	long long temp; // 임시 정수 변수

	// 크기 입력 받기
	int size = 0;
	scanf("%d", &size);

	// 정수 입력 받기
	for (int i = 0; i < size; i++) {
		scanf("%lld", &temp);

		// DP 갱신
		dp[i] = dp[i - 1] + temp > temp ? dp[i - 1] + temp : temp;
		
		// DP 최댓값
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	printf("%lld", max);

	return 0;
}