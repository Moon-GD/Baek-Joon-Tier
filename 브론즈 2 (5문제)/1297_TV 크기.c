// 참고 링크 : https://moon-gd.tistory.com/27
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double diagonal, height, width;

	// 입력 받기
	scanf("%lf %lf %lf", &diagonal, &height, &width);

	// 비율
	double ratio = diagonal / pow((height * height + width * width), 0.5);

	// 비율을 대입해서 높이, 너비 계산
	printf("%d %d", (int)(ratio * height), (int)(ratio * width));

	return 0;
}