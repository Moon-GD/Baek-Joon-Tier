#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, min, sec;
	int cook_time;

	// 현재 시간, 요리 시간 입력받기
	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &cook_time);

	sec += cook_time;

	while (sec >= 60) {
		min++;
		sec -= 60;

		// min이 허용 범위를 초과하는 경우
		if (min >= 60)	{
			min -= 60;
			hour++;
		}

		// hour이 허용 범위를 초과하는 경우
		if (hour >= 24) {
			hour = 0;
		}
	}

	// 출력
	printf("%d %d %d", hour, min, sec);

	return 0;
}