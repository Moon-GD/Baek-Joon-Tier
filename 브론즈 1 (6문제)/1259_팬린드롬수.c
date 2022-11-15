// 설명 링크 : https://moon-gd.tistory.com/101
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int number;

	while (1) {
		scanf("%d", &number);

		if (number == 0) {
			break;
		}
		
		// 문자열 선언
		char* str;
		str = (char*)malloc(5 * sizeof(char));

		sprintf(str, "%d", number);

		// str 마지막 가리키는 포인터 선언
		char* end_str = str + strlen(str) - 1;

		int flag = 1;
		while (str != end_str) {
			// 회문 조건 만족이 안되는 경우
			// no 출력 후 while 탈출
			if (*str != *end_str) {
				printf("no\n");
				// flag 0으로 변경
				flag = 0;
				break;
			}
			
			// 포인터 이동
			str++, end_str--;

			// 시작 지점의 포인터가 널 값에 도달한 경우 while 탈출
			if (*str == '\0') {
				break;
			}
		}

		// flag 변경이 없었다면, yes 출력
		if (flag) {
			printf("yes\n");
		}
	}

	return 0;
}