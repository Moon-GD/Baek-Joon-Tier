#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int person, area;
	int news[5];

	scanf("%d %d", &person, &area);
	
	for (int i = 0; i < 5; i++) {
		scanf("%d", &news[i]);
		printf("%d ", news[i] - person * area);
	}

	return 0;
}