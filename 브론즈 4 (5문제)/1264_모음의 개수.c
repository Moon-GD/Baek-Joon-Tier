#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 257

int main() {

	while (1) {
		char string[MAX];
		fgets(string, MAX, stdin);

		// 종료조건 마주치면 while 문 종료
		if (string[0] == '#') {
			break;
		}

		int count = 0, target = 0;

		// 모음 개수 확인
		while (string[count]) {
			// 대문자면 소문자로 치환
			if (65 <= string[count] && string[count] <= 90) {
				string[count] += 32;
			}
			
			// 소문자인 문자만 조건문 진입
			if (97 <= string[count] && string[count] <= 122)
			{
				if (string[count] == 'a' || string[count] == 'e' || string[count] == 'i' || string[count] == 'o' || string[count] == 'u') {
					target++;
				}
				
			}
			count++;
		}

		printf("%d\n", target);
	}

	return 0;
}