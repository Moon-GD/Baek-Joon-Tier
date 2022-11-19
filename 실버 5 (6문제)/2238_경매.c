// ���� ��ũ : https://moon-gd.tistory.com/41
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

	// ��� ���� �Է� �ޱ�
	for (int i = 0; i < bid_times; i++) {
		scanf("%s %d", person_names[i], &person_prices[i]);
		money[person_prices[i]] ++;
	}

	// ���� ���� ���� ���� ���ð� ã��
	for (int i = 0; i < upper_price; i++) {
		// 0�� �ƴ� ��츸
		if (money[i] && min > money[i]) {
			min = money[i];
			min_index = i;
		}
	}

	// �ּ� ���� ������ ��� ���� ���
	for (int i = 0; i < bid_times; i++) {
		if (person_prices[i] == min_index) {
			printf("%s %d", person_names[i], person_prices[i]);
			break;
		}
	}

	return 0;
}