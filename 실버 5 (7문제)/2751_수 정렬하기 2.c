// 설명 링크 : https://moon-gd.tistory.com/104
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000000

int numbers[MAX * 2 + 1];

int main() {
	int size = 0, temp_num;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &temp_num);
		numbers[temp_num + MAX]++;
	}

	for (int i = 0; i < MAX * 2 + 1; i++) {
		if (numbers[i]) {
			printf("%d\n", i - MAX);
		}
	}

	return 0;
}