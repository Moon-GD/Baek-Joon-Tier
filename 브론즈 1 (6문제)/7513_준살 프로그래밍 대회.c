// ���� ��ũ : https://moon-gd.tistory.com/35
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int test_size = 0;

	scanf("%d", &test_size);
	for (int i = 1; i <= test_size; i++) {
		printf("Scenario #%d:\n", i);
		char string[50][5];

		// �ܾ� ���� �Է� �ޱ�
		int string_count = 0;
		scanf("%d", &string_count);
		for (int j = 0; j < string_count; j++) {
			scanf("%s", string[j]);
		}

		// ������ ���� �Է� �ޱ�
		int player_count = 0;
		scanf("%d", &player_count);
		for (int j = 0; j < player_count; j++) {
			int password_count = 0;
			scanf("%d", &password_count);
			for (int k = 0; k < password_count; k++) {
				int temp;
				scanf("%d", &temp);
				printf("%s", string[temp]);
			}
			putchar('\n');
		}
		putchar('\n');
	}


	return 0;
}