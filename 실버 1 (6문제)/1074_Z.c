// ���� ��ũ : https://moon-gd.tistory.com/132
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow2(int number);

enum {
	UP, DOWN
};

enum {
	LEFT, RIGHT
};

int count = 0;  // �̵� Ƚ�� ����

int main() {
	int N, row, col;

	scanf("%d %d %d", &N, &row, &col);

	int length = pow2(N);
	
	while (length != 2) {
		int vertical = UP;  // ��, �Ʒ� flag
		int horizontal = LEFT;  // ��, �� flag

		// ��и� ��ġ ���
		if (length / 2 <= row) {
			vertical = DOWN;
			row -= length / 2;
		}
		if (length / 2 <= col) {
			horizontal = RIGHT;
			col -= length / 2;
		}

		// 1 ��и�
		if (vertical == UP && horizontal == LEFT) {
			
		}
		// 2 ��и�
		else if (vertical == UP && horizontal == RIGHT) {
			count += length * length / 4;
		}
		// 3 ��и�
		else if (vertical == DOWN && horizontal == LEFT) {
			count += length * length / 2;
		}
		// 4 ��и�
		else if (vertical == DOWN && horizontal == RIGHT) {
			count += length * length / 4 * 3;
		}

		length /= 2;
	}

	if (row == 0 && col == 0) {
		count += 0;
	}
	else if (row == 0 && col == 1) {
		count += 1;
	}
	else if (row == 1 && col == 0) {
		count += 2;
	}
	else if (row == 1 && col == 1) {
		count += 3;
	}

	printf("%d", count);

	return 0;
}

int pow2(int number) {
	if (number == 1) {
		return 2;
	}
	else {
		return 2 * pow2(number - 1);
	}
}