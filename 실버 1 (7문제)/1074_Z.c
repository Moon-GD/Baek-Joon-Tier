// 설명 링크 : https://moon-gd.tistory.com/132
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow2(int number);

enum {
	UP, DOWN
};

enum {
	LEFT, RIGHT
};

int count = 0;  // 이동 횟수 변수

int main() {
	int N, row, col;

	scanf("%d %d %d", &N, &row, &col);

	int length = pow2(N);
	
	while (length != 2) {
		int vertical = UP;  // 위, 아래 flag
		int horizontal = LEFT;  // 좌, 우 flag

		// 사분면 위치 계산
		if (length / 2 <= row) {
			vertical = DOWN;
			row -= length / 2;
		}
		if (length / 2 <= col) {
			horizontal = RIGHT;
			col -= length / 2;
		}

		// 1 사분면
		if (vertical == UP && horizontal == LEFT) {
			
		}
		// 2 사분면
		else if (vertical == UP && horizontal == RIGHT) {
			count += length * length / 4;
		}
		// 3 사분면
		else if (vertical == DOWN && horizontal == LEFT) {
			count += length * length / 2;
		}
		// 4 사분면
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