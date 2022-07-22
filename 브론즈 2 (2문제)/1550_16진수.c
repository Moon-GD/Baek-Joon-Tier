// # 참고 링크 : https://moon-gd.tistory.com/28
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen

int main() {
	int number = 0, count = 1;
	char hex[6];
	scanf("%s", hex);

	for (int i = strlen(hex) - 1; i >= 0; i--) {

		if (hex[i] >= 'A') {
			number += count * (hex[i] - 'A' + 10);
		}
		else {
			number += count * (hex[i] - '0');
		}
		count *= 16;
	}

	printf("%d", number);

	return 0;
}