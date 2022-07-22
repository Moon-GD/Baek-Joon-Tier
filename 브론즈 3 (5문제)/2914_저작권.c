#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int A, I;

	scanf("%d %d", &A, &I);

	double avg = (double)I - 0.999999;
	int melody = (int)(avg * A) + 1;

	printf("%d", melody);

	return 0;
}