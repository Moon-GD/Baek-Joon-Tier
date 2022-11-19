// 참고 링크 : https://moon-gd.tistory.com/41
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001

char person_names[MAX][11];
int person_prices[MAX];
int money[MAX];
int min = MAX, min_index = 0;

int main() {
	int upper_price, bid_times;

	scanf("%d %d", &upper_price, &bid_times);

	// 경매 정보 입력 받기
	for (int i = 0; i < bid_times; i++) {
		scanf("%s %d", person_names[i], &person_prices[i]);
		money[person_prices[i]] ++;
	}

	// 가장 적게 들어온 낙찰 제시가 찾기
	for (int i = 0; i < upper_price; i++) {
		// 0이 아닌 경우만
		if (money[i] && min > money[i]) {
			min = money[i];
			min_index = i;
		}
	}

	// 최소 낙찰 제시한 사람 정보 출력
	for (int i = 0; i < bid_times; i++) {
		if (person_prices[i] == min_index) {
			printf("%s %d", person_names[i], person_prices[i]);
			break;
		}
	}

	return 0;
}