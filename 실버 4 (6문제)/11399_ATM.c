// 참고 링크 : https://moon-gd.tistory.com/44
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int times[MAX];
int sum = 0;

void quick_sort(int left, int right);

int main() {

	// 사람 수와 필요한 시간 입력 받기
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &times[i]);
	}

	// 오름차순 정렬
	quick_sort(0, size - 1);

	// 누적 시간 계산
	for (int i = 0; i < size; i++) {
		sum += (size - i) * times[i];
	}

	printf("%d", sum);

	return 0;
}

// quick_sort
void quick_sort(int left, int right) {
	int L = left, R = right;
	int pivot = times[(left + right) / 2];

	do {
		while (times[L] < pivot) { L++; }
		while (times[R] > pivot) { R--; }

		if (L <= R) {
			int temp = times[L];
			times[L] = times[R];
			times[R] = temp;
			L++, R--;
		}
	} while (L <= R);

	if (left < R) {
		quick_sort(left, R);
	}

	if (L < right) {
		quick_sort(L, right);
	}
}