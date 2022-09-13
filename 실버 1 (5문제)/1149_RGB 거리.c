// 참고 링크 : https://moon-gd.tistory.com/71
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int red_array[MAX];
int green_array[MAX];
int blue_array[MAX];

int size = 0, i;
int red, green, blue;

int find_min(int a, int b, int c);

int main() {
	scanf("%d", &size);

	for (i = 0; i < size; i++) {
		scanf("%d %d %d", &red, &green, &blue);

		red_array[i + 1] = green_array[i] < blue_array[i] ? green_array[i] + red : blue_array[i] + red;
		green_array[i + 1] = red_array[i] < blue_array[i] ? red_array[i] + green : blue_array[i] + green;
		blue_array[i + 1] = red_array[i] < green_array[i] ? red_array[i] + blue : green_array[i] + blue;
	}

	printf("%d", find_min(red_array[i], green_array[i], blue_array[i]));

	return 0;
}

int find_min(int a, int b, int c) {
	if (a > b) {
		if (b > c) {
			return c;
		}
		else {
			return b;
		}
	}
	// b >= a
	else {
		if (a > c) {
			return c;
		}
		else {
			return a;
		}
	}
}