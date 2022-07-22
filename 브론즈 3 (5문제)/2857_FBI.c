#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strstr

int main() {
	int count = 0;
	for (int i = 1; i <= 5; i++) {
		char name[11];

		// 문자열 입력받기
		scanf("%s", name);

		// 문자열에 FBI가 포함되면 해당 요원 번호 출력
		if (strstr(name, "FBI")) {
			printf("%d\n", i);
		}
		else {
			count++;
		}
	}

	// FBI가 존재하지 않는 경우
	if (count == 5) {
		printf("HE GOT AWAY!");
	}

	return 0;
}