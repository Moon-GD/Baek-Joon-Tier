// ���� ��ũ : https://moon-gd.tistory.com/63
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int dp[MAX];  // ���� �� �κ� ���� ������ ������ �迭
// dp[x] : ���̰� X�� �� ���� �����ʿ� ���� ���Ҹ� �ǹ��մϴ�.

int main() {
	// �迭 ũ�� �Է� �ޱ�
	int size;
	scanf("%d", &size);

	int dp_index = 1;  // dp �迭�� �ε��� ����

	int i, j, temp;
	// i, j : �ݺ��� ��ȸ�� ���� ���
	// temp : �ӽ� ����

	for (i = 1; i <= size; i++) {
		scanf("%d", &temp);

		// ù ��° ��ȸ�� ���, DP �迭�� ����� ������ ���� ������ DP�� �״�� �����մϴ�.
		if (i == 1) {
			dp[dp_index] = temp;
		}
		// �� ��° ��ȸ���ʹ� �Ʒ��� �б⹮�� ������ �˴ϴ�.
		else {
			// �Է� ���� ����(temp)�� DP�� �ִ� ���ں��� ū ���, �״�� �̾��ָ� �˴ϴ�.
			// ex) dp = [10, 20, 30], temp = 50 -> dp = [10, 20, 30, 50]
			if (temp > dp[dp_index]) {
				dp[++dp_index] = temp;
			}

			// �Է� ���� ����(temp)�� DP�� �ִ� ���ں��� ũ�� ���� ���, �Ʒ��� �б⹮�� ������ �˴ϴ�.
			else {
				// DP �迭�� ��ȸ�ϸ� temp�� �� ���� ���� ã�� �˴ϴ�.
				for (j = 1; j <= dp_index; j++) {
					// ã�� ��� ������ ��ġ�� �������ݴϴ�.
					// ex) dp = [10, 20, 30], temp = 15 -> dp = [10, 15, 30]
					if (temp <= dp[j]) {
						dp[j] = temp;
						break;
					}
				}
			}
		}
	}

	// dp �迭�� ���̸� ����մϴ�.
	printf("%d", dp_index);

	return 0;
}