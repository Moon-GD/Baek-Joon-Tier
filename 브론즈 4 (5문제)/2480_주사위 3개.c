#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	// 모두 같은 경우
	if (a == b && b == c && c == a) {
		printf("%d", 10000 + a * 1000);
	}
	// 두 가지만 같은 경우 1
	else if (a == b || a == c) {
		printf("%d", 1000 + a * 100);
	}
	// 두 가지만 같은 경우 2
	else if (b == c) {
		printf("%d", 1000 + b * 100);
	}
	// 모두 다른 경우
	else {
		// a > b
		if (a > b) {
			// b > c
			if (b > c) {
				printf("%d", 100 * a);
			}
			// c >= b
			else {
				if (a > c) {
					printf("%d", a * 100);
				}
				else {
					printf("%d", c * 100);
				}
			}
		}
		// b >= a
		else {
			// a > c
			if (a > c) {
				printf("%d", 100 * b);
			}
			// c >= a
			else {
				if (b > c) {
					printf("%d", 100 * b);
				}
				else {
					printf("%d", 100 * c);
				}
			}
		}
	}

	return 0;
}