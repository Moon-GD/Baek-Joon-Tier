// 설명 링크 : https://moon-gd.tistory.com/102
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find_gcd(int num1, int num2);


int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int gcd = find_gcd(a, b), lcm = a * b / gcd;

	printf("%d\n", gcd);
	printf("%d", lcm);

	return 0;
}

int find_gcd(int num1, int num2) {
	int smaller_num = num1 < num2 ? num1 : num2;

	for (int i = smaller_num; i >= 1; i--) {
		if (num1 % i == 0 && num2 % i == 0) {
			return i;
		}
	}

	return 1;
}