// ���� ��ũ : https://moon-gd.tistory.com/33
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10001
int numbers[MAX];

int main() {
	int N = 0, temp;

	// �Է¹ޱ�
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		numbers[temp]++;
	}

	// ���
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < numbers[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}