#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000
int numbers[MAX];

void quick_sort(int left, int right);
void print_numbers(int size);

int main() {
	int size = 0;
	scanf("%d", &size);

	// 입력 받기
	for (int i = 0; i < size; i++) {
		scanf("%d", &numbers[i]);
	}

	// quick sort로 오름차 순 정렬
	quick_sort(0, size - 1);

	// 출력
	print_numbers(size);

	return 0;
}

void quick_sort(int left, int right) {
	int L = left, R = right;
	int pivot = numbers[(L + R) / 2];
	do {
		while (numbers[L] < pivot) { L++; }
		while (numbers[R] > pivot) { R--; }

		// 두 수 바꾸기
		if (L <= R) {
			int temp = numbers[L];
			numbers[L] = numbers[R];
			numbers[R] = temp;
			L++, R--;
		}
	} while (L <= R);


	if (L < right) {
		quick_sort(L, right);
	}

	if (left < R) {
		quick_sort(left, R);
	}
}

void print_numbers(int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", numbers[i]);
	}
	putchar('\n');
}