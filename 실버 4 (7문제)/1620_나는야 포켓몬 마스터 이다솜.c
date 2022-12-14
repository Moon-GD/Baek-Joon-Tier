// 설명 링크 : https://moon-gd.tistory.com/138
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100001
#include <stdio.h>
#include <string.h>  // strcmp
#include <stdlib.h>  // atoi

typedef struct node {
	char name[21];
	int number;
}node;

node number_book[MAX];
node name_book[MAX];

int N, M;

void quick_sort(int left, int right);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", &number_book[i].name);
		strcpy(name_book[i].name, number_book[i].name);
		name_book[i].number = i;
	}

	// name_book 정렬
	quick_sort(1, N);

	// 검색
	char find_string[21];
	for (int i = 0; i < M; i++) {
		scanf("%s", find_string);
		
		// 숫자인 경우
		if ('0' <= find_string[0] && find_string[0] <= '9') {
			printf("%s\n", number_book[atoi(find_string)].name);
		}
		// 이름인 경우
		else {
			int left = 1;
			int right = N;

			while (left <= right) {
				int middle = (left + right) / 2;
				int value = strcmp(name_book[middle].name, find_string);

				// 찾은 경우 : 포켓몬 도감 번호 반환
				if (value == 0) {
					printf("%d\n", name_book[middle].number);
					break;
				}
				else if (value > 0) {
					right = middle - 1;
				}
				else if (value < 0) {
					left = middle + 1;
				}
			}
		}
	}

	return 0;
}

void quick_sort(int left, int right) {
	int L = left;
	int R = right;
	
	char middle_name[20] = "";
	strcpy(middle_name, name_book[(L + R) / 2].name);

	do {
		while (strcmp(name_book[L].name, middle_name) < 0) {
			L++;
		}

		while (strcmp(name_book[R].name, middle_name) > 0) {
			R--;
		}

		if (L <= R) {
			char temp_string[25];
			strcpy(temp_string, name_book[L].name);
			strcpy(name_book[L].name, name_book[R].name);
			strcpy(name_book[R].name, temp_string);

			int temp_number;
			temp_number = name_book[L].number;
			name_book[L].number = name_book[R].number;
			name_book[R].number = temp_number;

			L++;
			R--;
		}

	} while (L <= R);

	if (L < right) {
		quick_sort(L, right);
	}

	if (left < R) {
		quick_sort(left, R);
	}
}