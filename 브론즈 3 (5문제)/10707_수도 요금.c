#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x_standard;
	int y_standard, y_upper_bound, y_surcharge;
	int usage;

	// 입력 받기 
	// 입력을 정수단위로 구분해서 받기 때문에 한 줄로 받아도 무관
	scanf("%d %d %d %d %d", &x_standard, &y_standard, &y_upper_bound, &y_surcharge, &usage);

	int x_fare = usage * x_standard;
	int y_fare = 0;

	// y사의 기본 사용량을 초과한 경우
	if (usage > y_upper_bound) {
		y_fare = y_standard + (usage - y_upper_bound) * y_surcharge;
	}
	// y사에서 기본 요금만 부과되는 경우
	else {
		y_fare = y_standard;
	}


	// 가격 비교 후 최소값 출력
	if (x_fare <= y_fare) {
		printf("%d", x_fare);
	}
	else {
		printf("%d", y_fare);
	}

	return 0;
}