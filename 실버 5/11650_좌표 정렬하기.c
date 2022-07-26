// 참고 링크 : https://moon-gd.tistory.com/37
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int vertex[MAX][2];
int count[MAX * 2 + 1];  // -10만 ~ 10만까지 총 20만 1개의 정수를 담기 위해 MAX * 2 + 1로 선언

// quick_sort 함수
// 세 번째 인자인 point = 0 -> x 좌표 기준 정렬, point = 1 -> y 좌표 기준 정렬
void quick_sort(int left, int right, int point);

// 좌표 출력 함수
void print_vertex(int size);

int main() {
	// 점 입력받기
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d %d", &vertex[i][0], &vertex[i][1]);

		// count 배열이 존재하는 이유는 x 좌표가 겹치는 곳이 있는지 체크하기 위함.
		// x 좌표가 -10만인 경우 0번째 인덱스, x 좌표가 0 인 경우, 10만번째 인덱스 1 증가
		count[vertex[i][0] + MAX]++;
	}

	// x 좌표 기준 정렬
	quick_sort(0, size - 1, 0);

	// count 배열을 활용해서 x 좌표가 겹치는 곳이 있는지 순차적 탐색
	// 여러 개인 경우, y 좌표 기준으로 정렬
	for (int i = 0; i < size; i++) {
		// 만약 x 좌표의 개수가 1개보다 많다면, 해당 범위에서 y 좌표 기준으로 quick_sort를 한 번 더 해줍니다.
		if (count[vertex[i][0] + MAX] > 1) {
			quick_sort(i, i + count[vertex[i][0] + MAX] - 1, 1);
			i += count[vertex[i][0] + MAX] - 1;
		}
	}

	// 출력
	print_vertex(size);

	return 0;
}

void quick_sort(int left, int right, int point) {
	int L = left, R = right;
	int pivot = vertex[(left + right) / 2][point];

	do {
		while (vertex[L][point] < pivot) { L++; }
		while (vertex[R][point] > pivot) { R--; }

		if (L <= R) {
			// x 좌표 바꾸기
			int temp = vertex[L][0];
			vertex[L][0] = vertex[R][0];
			vertex[R][0] = temp;

			// y 좌표 바꾸기
			temp = vertex[L][1];
			vertex[L][1] = vertex[R][1];
			vertex[R][1] = temp;
			L++, R--;
		}
	} while (L <= R);


	if (left < R) {
		quick_sort(left, R, point);
	}

	if (L < right) {
		quick_sort(L, right, point);
	}
}

// 좌표 출력 함수
void print_vertex(int size) {
	for (int i = 0; i < size; i++) {
		printf("%d %d\n", vertex[i][0], vertex[i][1]);
	}
}