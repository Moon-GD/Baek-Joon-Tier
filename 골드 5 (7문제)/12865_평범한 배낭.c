// 설명 링크 : https://moon-gd.tistory.com/77
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101 // 최대 물건 개수
#define MAX_CAPACITY 100001  // 최대 물건 용량

// 물건 정보를 담기 위한 구조체 및 구조체 배열
typedef struct node {
	int weight;
	int value;
}node;
node items[MAX];

// DP 배열
int tables[MAX][MAX_CAPACITY];

// 반복문 순회 변수
int i, j;

int main() {
	int size, capacity;

	// 가방 정보 입력 받기
	scanf("%d %d", &size, &capacity);

	// 물건 정보 입력 받기
	for (i = 1; i <= size; i++) {
		scanf("%d %d", &items[i].weight, &items[i].value);
	}

	// DP 배열 업데이트 과정
	for (i = 1; i <= size; i++) {
		for (j = i; j <= capacity; j++) {
			if (j < items[i].weight) {
				tables[i][j] = tables[i - 1][j];
			}
			else {
				tables[i][j] = tables[i - 1][j] > tables[i - 1][j - items[i].weight] + items[i].value ? 
					tables[i - 1][j] : tables[i - 1][j - items[i].weight] + items[i].value;
			}
		}
	}
	
	// 최종 값 출력
	printf("%d", tables[size][capacity]);

	return 0;
}