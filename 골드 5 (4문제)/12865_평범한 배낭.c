// ���� ��ũ : https://moon-gd.tistory.com/77
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101 // �ִ� ���� ����
#define MAX_CAPACITY 100001  // �ִ� ���� �뷮

// ���� ������ ��� ���� ����ü �� ����ü �迭
typedef struct node {
	int weight;
	int value;
}node;
node items[MAX];

// DP �迭
int tables[MAX][MAX_CAPACITY];

// �ݺ��� ��ȸ ����
int i, j;

int main() {
	int size, capacity;

	// ���� ���� �Է� �ޱ�
	scanf("%d %d", &size, &capacity);

	// ���� ���� �Է� �ޱ�
	for (i = 1; i <= size; i++) {
		scanf("%d %d", &items[i].weight, &items[i].value);
	}

	// DP �迭 ������Ʈ ����
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
	
	// ���� �� ���
	printf("%d", tables[size][capacity]);

	return 0;
}