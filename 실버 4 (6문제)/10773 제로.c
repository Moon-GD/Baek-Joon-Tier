// ���� ��ũ : https://moon-gd.tistory.com/48
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int stack[MAX], top = -1, sum = 0;

int main() {
	int size = 0;
	scanf("%d", &size);

	// �Է¹����鼭 �հ� ���
	for (int i = 0; i < size; i++) {
		scanf("%d", &stack[++top]);
		// 0�� �ƴ� ������ ���� ���
		if (stack[top]) {
			sum += stack[top];
		}
		// 0�� ���� ���
		else {
			sum -= stack[top - 1];
			top -= 2;
		}
	}

	printf("%d", sum);

	return 0;
}