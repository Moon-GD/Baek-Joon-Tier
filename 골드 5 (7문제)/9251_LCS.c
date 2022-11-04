// 설명 링크 : https://moon-gd.tistory.com/96

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX(a, b) a > b ? a : b
#define MAX_LENGTH 1000

char A[MAX_LENGTH + 1];
char B[MAX_LENGTH + 1];

int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main() {
	// 문자열 입력
	scanf("%s", &A);
	scanf("%s", &B);
	
	// 길이 확인
	int len_A = strlen(A);
	int len_B = strlen(B);

	// 결과 출력 : 빈 문자열이 있는 경우 0 출력 후 종료
	if (len_A == 0 || len_B == 0) {
		printf("0");
		return 0;
	}

	for (int i = 1; i <= len_B; i++) {
		for (int j = 1; j <= len_A; j++) {
			if (B[i - 1] == A[j - 1]) {
				dp[j][i] = dp[j - 1][i - 1] + 1;
			}
			else {
				dp[j][i] = MAX(dp[j - 1][i], dp[j][i - 1]);
			}
		}
	}

	printf("%d", dp[len_A][len_B]);

	return 0;
}