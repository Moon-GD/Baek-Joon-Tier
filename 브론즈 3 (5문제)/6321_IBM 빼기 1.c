#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen

int main() {
	int size = 0;
	scanf("%d", &size);

	for (int i = 1; i <= size; i++) {
		// 문자열 선언 및 입력받기
		char string[52];
		scanf("%s", string);

		printf("String #%d\n", i);
		// 문자열 변환
		for (int j = 0; j < (int)strlen(string); j++) {
			if (string[j] == 'Z') {
				printf("A");
			}
			else {
				printf("%c", string[j] + 1);
			}
		}

		// 공백 출력을 위한 printf 함수 호출
		printf("\n\n");
	}

	return 0;
}