// ���� ��ũ : https://moon-gd.tistory.com/101
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int number;

	while (1) {
		scanf("%d", &number);

		if (number == 0) {
			break;
		}
		
		// ���ڿ� ����
		char* str;
		str = (char*)malloc(5 * sizeof(char));

		sprintf(str, "%d", number);

		// str ������ ����Ű�� ������ ����
		char* end_str = str + strlen(str) - 1;

		int flag = 1;
		while (str != end_str) {
			// ȸ�� ���� ������ �ȵǴ� ���
			// no ��� �� while Ż��
			if (*str != *end_str) {
				printf("no\n");
				// flag 0���� ����
				flag = 0;
				break;
			}
			
			// ������ �̵�
			str++, end_str--;

			// ���� ������ �����Ͱ� �� ���� ������ ��� while Ż��
			if (*str == '\0') {
				break;
			}
		}

		// flag ������ �����ٸ�, yes ���
		if (flag) {
			printf("yes\n");
		}
	}

	return 0;
}