// 참고 링크 : https://moon-gd.tistory.com/36
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char sentence[5000000];

int main() {
	long long sum = 0;
	int hidden_number = 0;
	int length = 0;
	char temp_c;

	scanf("%d", &length);
	scanf("%c", &temp_c);
	scanf("%s", sentence);
	for (int i = 0; i < length; i++) {
		temp_c = sentence[i];
		// 숫자인 경우
		if (0 <= temp_c - '0' && temp_c - '0' <= 9) {
			if (hidden_number == 0) {
				hidden_number += temp_c - '0';
			}
			else {
				hidden_number *= 10;
				hidden_number += temp_c - '0';
			}
		}
		else {
			sum += hidden_number;
			hidden_number = 0;
		}
	}

	// 마지막에 숫자가 들어온 경우 hidden_number 값이 아직 남아있기 때문에 더해준다
	sum += hidden_number;

	// 합 출력
	printf("%lld", sum);

	return 0;
}