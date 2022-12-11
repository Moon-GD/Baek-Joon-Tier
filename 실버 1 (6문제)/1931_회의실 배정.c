// 설명 링크 : https://moon-gd.tistory.com/75
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001

typedef struct node {
	int start;
	int end;
}node;

node meetings[MAX];

int array[MAX];

void quick_sort(int left, int right);
void front_sort(int left, int right);

int main() {
	int i;
	int size = 0;

	// 회의 정보 입력 받기
	scanf("%d", &size);
	for (i = 1; i <= size; i++) {
		scanf("%d %d", &meetings[i].start, &meetings[i].end);
	}

	// 퀵 정렬
	quick_sort(1, size);

	// 7 7
	// 6 7
	// 위와 같은 경우 6 7 이 먼저 나오도록 정렬해줘야 함
	for (i = 1; i <= size;) {
		int start_index = i;
		while (meetings[i].end == meetings[i + 1].end) {
			i++;
		}

		front_sort(start_index, i);
		i++;
	}

	int count = 1;
	int last_index = meetings[1].end;
	for (i = 2; i <= size; i++) {
		if (meetings[i].start < last_index) {
			continue;
		}
		else {
			last_index = meetings[i].end;
			count++;
		}
	}

	printf("%d", count);
}

void quick_sort(int left, int right) {
	int L = left;
	int R = right;
	int pivot = meetings[(L + R) / 2].end;

	do {
		while (meetings[L].end < pivot) {
			L++;
		}

		while (meetings[R].end > pivot) {
			R--;
		}

		if (L <= R) {
			node temp = meetings[L];
			meetings[L] = meetings[R];
			meetings[R] = temp;
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

void front_sort(int left, int right) {
	int L = left;
	int R = right;
	int pivot = meetings[(L + R) / 2].start;

	do {
		while (meetings[L].start < pivot) {
			L++;
		}

		while (meetings[R].start > pivot) {
			R--;
		}

		if (L <= R) {
			node temp = meetings[L];
			meetings[L] = meetings[R];
			meetings[R] = temp;
			L++, R--;
		}

	} while (L <= R);

	if (left < R) {
		front_sort(left, R);
	}

	if (L < right) {
		front_sort(L, right);
	}
}