// ���� ��ũ : https://moon-gd.tistory.com/42
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 51

int main() {

	// ���ڿ� ���� �Է� �ޱ�
	int size = 0;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		// ���ڿ� �Է� �ޱ�
		char string[MAX];
		scanf("%s", string);

		int count = 0;
		for (int j = 0; j < (int)strlen(string); j++) {
			// ���� ��ȣ�� ���� ���
			if (string[j] == '(') {
				count++;
			}
			// ������ ��ȣ�� ���� ���
			else if (string[j] == ')') {
				count--;
			}

			// count�� ������ ��� -> ������ ��ȣ�� ���� ��ȣ���� ���� ���� �� ������ �ǹ�
			// ���� for �� �����ϰ� NO ���
			if (count < 0) {
				break;
			}
		}

		// ������ ��ȣ�� ���� ��ȣ�� ����, ������ �ùٸ� ���
		if (count == 0) {
			printf("YES\n");
		}
		// �ݴ��� ���
		else {
			printf("NO\n");
		}
	}

	return 0;
}