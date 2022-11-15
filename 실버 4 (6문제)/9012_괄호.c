// 참고 링크 : https://moon-gd.tistory.com/42
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 51

int main() {

	// 문자열 개수 입력 받기
	int size = 0;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		// 문자열 입력 받기
		char string[MAX];
		scanf("%s", string);

		int count = 0;
		for (int j = 0; j < (int)strlen(string); j++) {
			// 왼쪽 괄호가 들어온 경우
			if (string[j] == '(') {
				count++;
			}
			// 오른쪽 괄호가 들어온 경우
			else if (string[j] == ')') {
				count--;
			}

			// count가 음수인 경우 -> 오른쪽 괄호가 왼쪽 괄호보다 먼저 들어온 게 있음을 의미
			// 따라서 for 문 종료하고 NO 출력
			if (count < 0) {
				break;
			}
		}

		// 오른쪽 괄호와 왼쪽 괄호의 순서, 개수가 올바른 경우
		if (count == 0) {
			printf("YES\n");
		}
		// 반대의 경우
		else {
			printf("NO\n");
		}
	}

	return 0;
}