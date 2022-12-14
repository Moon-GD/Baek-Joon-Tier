// 참고 링크 : https://moon-gd.tistory.com/45
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int coins[MAX];

int main() {

	// 입력 받기
	int size, target_value = 0;
	scanf("%d %d", &size, &target_value);
	for (int i = 0; i < size; i++) {
		scanf("%d", &coins[i]);
	}

	// 제일 값어치가 큰 동전부터 저장하기 위해 마지막 인덱스 값 저장
	int index = size - 1;

	// 동전 개수 저장하기 위한 변수
	int count = 0;

	while (1) {
		count += target_value / coins[index];
		target_value %= coins[index--];

		if (index < 0) {
			break;
		}
	}

	// 총 필요한 동전 개수 출력
	printf("%d", count);

	return 0;
}