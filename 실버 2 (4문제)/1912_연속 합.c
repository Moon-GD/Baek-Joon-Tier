// ���� ��ũ : https://moon-gd.tistory.com/66
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

// DP �迭
long long dp[MAX];

int main() {
	long long max = -1000;
	long long temp; // �ӽ� ���� ����

	// ũ�� �Է� �ޱ�
	int size = 0;
	scanf("%d", &size);

	// ���� �Է� �ޱ�
	for (int i = 0; i < size; i++) {
		scanf("%lld", &temp);

		// DP ����
		dp[i] = dp[i - 1] + temp > temp ? dp[i - 1] + temp : temp;
		
		// DP �ִ�
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	printf("%lld", max);

	return 0;
}