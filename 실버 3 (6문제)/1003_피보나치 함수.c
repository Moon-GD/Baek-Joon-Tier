// 참고 링크 : https://moon-gd.tistory.com/50
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 41

int zero[MAX] = { 1, 0 };
int one[MAX] = {0, 1};


int main() {
	for (int i = 2; i < MAX; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	int test_num, num;
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		scanf("%d", &num);
		printf("%d %d\n", zero[num], one[num]);
	}


	return 0;
}