// 참고 링크 : https://moon-gd.tistory.com/52
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 11

int cases[MAX]= {0, 1, 2, 4};

int main() {
	for (int i = 4; i < MAX; i++) {
		cases[i] = cases[i - 1] + cases[i - 2] + cases[i - 3];
	}

	int test_num = 0, temp;
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		scanf("%d", &temp);
		printf("%d\n", cases[temp]);
	}

	return 0;
}