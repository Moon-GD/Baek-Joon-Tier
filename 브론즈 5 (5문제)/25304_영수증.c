#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int N;

int main() {
	int price, sum = 0;
	scanf("%d %d", &price, &N);
	
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		sum += a * b;
	}

	if (sum == price) {
		printf("Yes");
	}
	else {
		printf("No");
	}

	return 0;
}