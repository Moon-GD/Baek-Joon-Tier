// 설명 링크 : https://moon-gd.tistory.com/99
#define _CRT_SECURE_NO_WARNINGS
#define MAX 15
#include <stdio.h>
#include <math.h>

int size = 0, goal = 0;
int columns[MAX];

void queen(int depth);
int validity(int depth);

int main() {
	scanf("%d", &size);

	queen(0);

	printf("%d", goal);

	return 0;
}

void queen(int depth) {
	if (validity(depth)) {
		if (depth == size) {
			goal++;
			return;
		}
		else {
			for (int i = 1; i <= size; i++) {
				columns[depth + 1] = i;
				queen(depth + 1);
			}
		}
	}
}

int validity(int depth) {
	for (int i = 1; i < depth; i++) {
		if (columns[i] == columns[depth] || depth - i == abs(columns[depth] - columns[i])) {
			return 0;
		}
	}

	return 1;
}