// 참고 링크 : https://moon-gd.tistory.com/63
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int dp[MAX];  // 가장 긴 부분 수열 정보를 저장할 배열
// dp[x] : 길이가 X일 때 가장 오른쪽에 오는 원소를 의미합니다.

int main() {
	// 배열 크기 입력 받기
	int size;
	scanf("%d", &size);

	int dp_index = 1;  // dp 배열의 인덱스 변수

	int i, j, temp;
	// i, j : 반복문 순회를 위해 사용
	// temp : 임시 정수

	for (i = 1; i <= size; i++) {
		scanf("%d", &temp);

		// 첫 번째 순회인 경우, DP 배열에 저장된 정보가 없기 때문에 DP에 그대로 삽입합니다.
		if (i == 1) {
			dp[dp_index] = temp;
		}
		// 두 번째 순회부터는 아래의 분기문을 따르게 됩니다.
		else {
			// 입력 받은 숫자(temp)가 DP의 최대 숫자보다 큰 경우, 그대로 이어주면 됩니다.
			// ex) dp = [10, 20, 30], temp = 50 -> dp = [10, 20, 30, 50]
			if (temp > dp[dp_index]) {
				dp[++dp_index] = temp;
			}

			// 입력 받은 숫자(temp)가 DP의 최대 숫자보다 크지 않은 경우, 아래의 분기문을 따르게 됩니다.
			else {
				// DP 배열을 순회하며 temp가 들어갈 만한 곳을 찾게 됩니다.
				for (j = 1; j <= dp_index; j++) {
					// 찾은 경우 적당한 위치에 삽입해줍니다.
					// ex) dp = [10, 20, 30], temp = 15 -> dp = [10, 15, 30]
					if (temp <= dp[j]) {
						dp[j] = temp;
						break;
					}
				}
			}
		}
	}

	// dp 배열의 길이를 출력합니다.
	printf("%d", dp_index);

	return 0;
}