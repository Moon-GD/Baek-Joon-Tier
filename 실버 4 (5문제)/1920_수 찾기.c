// 참고 링크 : https://moon-gd.tistory.com/47
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001

// 전역 변수 공간
int numbers[MAX];
int goals[MAX];
int input_size, output_size, to_find;

// 전역 함수 공간
void merge_sort(int left, int right);
void merge(int left, int mid, int right);
void binary_search(int to_find, int start, int end);

int main() {
	
	// 입력 받기
	scanf("%d", &input_size);
	for (int i = 0; i < input_size; i++) {
		scanf("%d", &numbers[i]);
	}

	// 오름차순 정렬하기 (merge sort)
	merge_sort(0, input_size - 1);

	// 출력 관련 정보 입력 받기
	scanf("%d", &output_size);
	for (int i = 0; i < output_size; i++) {
		scanf("%d", &to_find);
		binary_search(to_find, 0, input_size - 1);
	}

	return 0;
}

void binary_search(int to_find, int start, int end) {
	int middle = (start + end) >> 1;
	while (1) {
		if (start >= end) {
			if (numbers[middle] == to_find) {
				printf("1\n");
				return;
			}
			printf("0\n");
			return;
		}

		if (numbers[middle] == to_find) {
			printf("1\n");
			return;
		}
		else if (to_find < numbers[middle]) {
			end = middle;
			middle = (start + end) >> 1;
		}
		else if (to_find > numbers[middle]) {
			start = middle + 1;
			middle = (start + end) >> 1;
		}
	}
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right) {
	int left_start = left;
	int right_start = mid + 1;
	int new_index = 0;

	while (left_start <= mid && right_start <= right) {

		if (numbers[left_start] < numbers[right_start]) {
			goals[new_index++] = numbers[left_start++];
		}
		else {
			goals[new_index++] = numbers[right_start++];
		}
	}

	while (left_start <= mid) {
		goals[new_index++] = numbers[left_start++];
	}

	while (right_start <= right) {
		goals[new_index++] = numbers[right_start++];
	}

	new_index--;
	while (new_index >= 0) {
		numbers[left + new_index] = goals[new_index];
		new_index--;
	}
}