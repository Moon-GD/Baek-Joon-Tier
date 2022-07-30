// 참고 링크 : https://moon-gd.tistory.com/48
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int stack[MAX], top = -1, sum = 0;

int main() {
	int size = 0;
	scanf("%d", &size);

	// 입력받으면서 합계 계산
	for (int i = 0; i < size; i++) {
		scanf("%d", &stack[++top]);
		// 0이 아닌 정수가 들어올 경우
		if (stack[top]) {
			sum += stack[top];
		}
		// 0이 들어올 경우
		else {
			sum -= stack[top - 1];
			top -= 2;
		}
	}

	printf("%d", sum);

	return 0;
}