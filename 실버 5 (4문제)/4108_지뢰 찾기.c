// 참고 링크 : https://moon-gd.tistory.com/38
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

int dirRow[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dirCol[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
char road[MAX][MAX];
int row, col;

int main() {

	while (1) {
		// 행과 열 입력받기
		scanf("%d %d", &row, &col);

		// 둘 다 0이 입력되면 종료
		if (row + col == 0) {
			break;
		}
		
		for (int i = 0; i < row; i++) {
			scanf("%s", road[i]);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// 지뢰인 경우 continue
				if (road[i][j] == '*') {
					continue;
				}
				// 지뢰가 아닌 경우, 주변 지뢰의 개수 확인
				int count = 0;
				for (int k = 0; k < 8; k++) {
					// 유효 범위를 벗어난 경우 continue
					if (dirRow[k] + i < 0 || dirRow[k] + i >= row || dirCol[k] + j < 0 || dirCol[k] + j >= col) {
						continue;
					}

					// 유효 범위 내에서 지뢰가 있을 경우 count 1 증가
					if (road[i + dirRow[k]][j + dirCol[k]] == '*') {
						count++;
					}
				}
				road[i][j] = '0' + count;
			}
		}

		for (int i = 0; i < row; i++) {
			printf("%s\n", road[i]);
		}
	}


	return 0;
}