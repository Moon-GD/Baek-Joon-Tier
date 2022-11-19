// ���� ��ũ : https://moon-gd.tistory.com/105
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>  // abs

int get_length(int num);  // ���� Digit �ڸ��� ��ȯ �Լ�


int main() {
	int target_channel = 0;  // ��ǥ ä��
	int err_size = 0;  // ���峭 ��ư ����
	int buttons[10] = { 0 };  // 0 : ����, 1 : ����
	int temp_num = 0; // �ӽ� ���� ����
	int count = 0;

	scanf("%d %d", &target_channel, &err_size);
	for (int i = 0; i < err_size; i++) {
		scanf("%d", &temp_num);
		buttons[temp_num]++;
	}

	// Finish : ��ǥ ä���� 100���� ���
	if (target_channel == 100) {
		printf("0");
		return 0;
	}
	// �ƴ� ��� count ���� �ʱ�ȭ
	else {
		count = abs(100 - target_channel);
	}

	int flag = 0;
	for (int i = 0; i <= 1000000; i++) {
		temp_num = i;
		flag = 0;
		
		do {
			// ���� �� ���峭 ��ư�� ���ԵǾ� �ִ� ���
			if (buttons[temp_num % 10]) {
				flag = 1;
				break;
			}
			else {
				temp_num /= 10;
			}
		} while (temp_num);
		
		// ���� ���������� �� �� �ִ� ��ȣ�� ���
		if (flag == 0) {
			// ���� ���� ���
			int length = get_length(i);
			length = length < abs(100 - i) ? length : abs(100 - i);
			
			count = count < abs(i - target_channel) + length ? count : abs(i - target_channel) + length;

			if (i > target_channel) {
				break;
			}
		}
	}

	// ��� ���
	printf("%d", count);

	return 0;
}

int get_length(int num) {
	// �� �ڸ� ���� ���
	if (0 <= num && num < 9) {
		return 1;
	}
	// �� �ڸ� �̻��� ���
	else {
		int length = 0;
		while (num) {
			length++;
			num /= 10;
		}

		// ���� ��ȯ
		return length;
	}
}