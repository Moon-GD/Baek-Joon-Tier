// 참고 링크 : https://moon-gd.tistory.com/58
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 51

int dir_x[4] = { 0, 1, 0 , -1 };
int dir_y[4] = { -1, 0, 1, 0 };
int ground[MAX][MAX];
int parent[MAX][MAX];
int x_size, y_size, connect_size;

typedef struct node {
	int x;
	int y;
}node;
node stack[MAX * MAX]; 
int parent_index = 0;

void bfs(int x, int y);

int main() {
	int test;
	scanf("%d", &test);

	for (int i = 1; i <= test; i++) {
		scanf("%d %d %d", &x_size, &y_size, &connect_size);
		int x, y;
		parent_index = 1;
		for (int j = 0; j < connect_size; j++) {
			scanf("%d %d", &x, &y);
			ground[x][y] = 1;
			node temp = { x, y };
			stack[j] = temp;
		}

		// 하나씩 꺼내가면서 부모 체크
		for (int j = 0; j < connect_size; j++) {
			x = stack[j].x, y = stack[j].y;
			if (parent[x][y]) {
				continue;
			}
			bfs(x, y);
			parent_index++;
		}

		// 결과 출력
		printf("%d\n", parent_index - 1);

		for (int j = 0; j < y_size; j++) {
			for (int k = 0; k < x_size; k++) {
				ground[k][j] = 0;
				parent[k][j] = 0;
			}
		}
	}


	return 0;
}

void bfs(int x, int y) {
	if (parent[x][y]) {
		return;
	}
	parent[x][y] = parent_index;

	for (int i = 0; i < 4; i++) {
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		// continue : 유효 범위를 벗어난 경우 1
		if (new_x < 0 || new_y < 0) {
			continue;
		}

		// continue : 유효 범위를 벗어난 경우 2
		if (new_x >= x_size || new_y >= y_size) {
			continue;
		}

		// continue : 이미 부모가 체크된 경우
		if (parent[new_x][new_y]) {
			continue;
		}

		if (ground[new_x][new_y]) {
			bfs(new_x, new_y);
		}
	}
}