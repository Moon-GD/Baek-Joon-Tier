// ���� ��ũ : https://moon-gd.tistory.com/133
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 51

// ��� ��, ��Ƽ ��, ������ �ƴ� ��� ��
int person_number, party_number, know_true_number;

int party[MAX][MAX];

// ������ �ƴ� ��� ����
// ���� 1�� ��� : ������ �ƴ� ���
// ���� 0�� ��� : ������ �𸣴� ���
int know_true[MAX];

// ������ �˰� �� ��� ������ �������ִ� �Լ�
// ���Ӱ� ������ �˰� �� ����� ���� ��� : return 1
// ������ ���� ��� : return 0
int update();

int main() {
	// �Է� : ��� ��, ��Ƽ ��, ������ �ƴ� ��� ��
	scanf("%d %d %d", &person_number, &party_number, &know_true_number);

	// �Է� : ������ �ƴ� ��� ����
	int temp_num;
	for (int i = 0; i < know_true_number; i++) {
		scanf("%d", &temp_num);
		know_true[temp_num] = 1;
	}

	// �Է� : ��Ƽ �ο� ��, ��Ƽ ���� �ο�
	for (int i = 0; i < party_number; i++) {
		scanf("%d", &party[i][0]);

		for (int j = 1; j <= party[i][0]; j++) {
			scanf("%d", &party[i][j]);
		}
	}

	// ������ �߻����� ���� ��� while�� Ż��
	do {
	} while (update());

	// ��� ���
	int count = 0;
	for (int i = 0; i < party_number; i++) {
		// ��Ƽ �ο��� 0�� �ƴ϶��? update() �Լ��� ������ ���� �ʾ����� �ǹ�
		// �̴� ��Ƽ �ο��� ��� ������ �𸥴ٴ� ���� �ǹ�!
		// ���� count�� 1�� �����ش�
		if (party[i][0]) {
			count++;
		}
	}

	// ��� ���
	printf("%d", count);

	return 0;
}

// ������ �˰� �� ��� ������ �������ִ� �Լ�
// ���Ӱ� ������ �˰� �� ����� ���� ��� : return 1
// ������ ���� ��� : return 0
int update() {
	int changed = 0;
	for (int i = 0; i < party_number; i++) {
		int flag = 0;
		for (int j = 1; j <= party[i][0]; j++) {
			if (know_true[party[i][j]]) {
				flag = 1;
				break;
			}
		}

		if (flag) {
			for (int j = 1; j <= party[i][0]; j++) {
				if (know_true[party[i][j]] == 0) {
					know_true[party[i][j]] = 1;
					changed = 1;
				}
			}
			party[i][0] = 0;
		}
	}

	return changed;
}