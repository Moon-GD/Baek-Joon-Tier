// ���� ��ũ : https://moon-gd.tistory.com/45
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int coins[MAX];

int main() {

	// �Է� �ޱ�
	int size, target_value = 0;
	scanf("%d %d", &size, &target_value);
	for (int i = 0; i < size; i++) {
		scanf("%d", &coins[i]);
	}

	// ���� ����ġ�� ū �������� �����ϱ� ���� ������ �ε��� �� ����
	int index = size - 1;

	// ���� ���� �����ϱ� ���� ����
	int count = 0;

	while (1) {
		count += target_value / coins[index];
		target_value %= coins[index--];

		if (index < 0) {
			break;
		}
	}

	// �� �ʿ��� ���� ���� ���
	printf("%d", count);

	return 0;
}