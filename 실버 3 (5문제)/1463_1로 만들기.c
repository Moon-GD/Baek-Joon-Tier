// ���� ��ũ : https://moon-gd.tistory.com/49
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001

int numbers[MAX] = { 0, 0, 1, 1 };

int main() {
	int size = 0;
	scanf("%d", &size);

	// dp ���
	for (int i = 4; i <= size; i++) {
		// �켱 i - 1 ��° �� + 1 �� ����
		numbers[i] = numbers[i - 1] + 1;

		// 2�� ���������� ��� Ȯ��
		if (i % 2 == 0 && numbers[i / 2]) {
			numbers[i] = numbers[i] < numbers[i / 2] + 1 ? numbers[i] : numbers[i / 2] + 1;
		}

		// 3���� ���������� ��� Ȯ��
		if (i % 3 == 0 && numbers[i / 3]) {
			numbers[i] = numbers[i] < numbers[i / 3] + 1 ? numbers[i] : numbers[i / 3] + 1;
		}
	}

	printf("%d", numbers[size]);

	return 0;
}