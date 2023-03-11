// 설명 링크 : https://moon-gd.tistory.com/150
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000000

int i;
int input_size = 0;
int results[MAX];

typedef struct node {
	int original_index;
	int value;
}node;
node coordinates[MAX];

void get_input();
void swap(int* a, int* b);
void quick_sort(int left, int right);
void get_order();
void print_results();

int main() {
	get_input();
	quick_sort(0, input_size - 1);
	get_order();
	print_results();
	
	return 0;
}

void get_input() {
	scanf("%d", &input_size);

	for (i = 0; i < input_size; i++) {
		scanf("%d", &coordinates[i].value);
		coordinates[i].original_index = i;
	}
}

void swap(int* a, int* b) {
	int temp_num = *a;
	*a = *b;
	*b = temp_num;
}

void quick_sort(int left, int right) {
	int L = left, R = right;
	int pivot = coordinates[(L + R) / 2].value;

	do {
		while (coordinates[L].value < pivot) { L++; }
		while (coordinates[R].value > pivot) { R--; }

		if (L <= R) {
			swap(&coordinates[L].value, &coordinates[R].value);
			swap(&coordinates[L].original_index, &coordinates[R].original_index);
			L++, R--;
		}
	} while (L < R);

	if (L < right) {
		quick_sort(L, right);
	}

	if (left < R) {
		quick_sort(left, R);
	}
}

void get_order() {
	int repeated_count = 0;

	for (i = 0; i < input_size; i++) {
		if (i != 0 && coordinates[i - 1].value == coordinates[i].value) {
			results[coordinates[i].original_index] = results[coordinates[i - 1].original_index];
			repeated_count++;
			continue;
		}

		results[coordinates[i].original_index] = i - repeated_count;
	}
}

void print_results() {
	for (i = 0; i < input_size; i++) {
		printf("%d ", results[i]);
	}
}