// 설명 링크 : https://moon-gd.tistory.com/137
#define _CRT_SECURE_NO_WARNINGS
#define MAX 21
#include <stdio.h>
#include <string.h>

int number_check[MAX];  // 집합에 숫자가 있는지 체크
char command[6];  // 명령어 입력을 위한 배열
int number = 0;

void all();
void empty();

int main() {
	int M = 0;
	scanf("%d\n", &M);

	for (int i = 0; i < M; i++) {
		scanf("%s", &command);

		switch (command[0]) {
			// add, all
			case 'a':
				// add
				if (command[1] == 'd') {
					scanf("%d", &number);
					number_check[number] = 1;
				}
				// all
				else {
					all();
				}
				break;

			// remove
			case 'r':
				scanf("%d", &number);
				number_check[number] = 0;
				break;

			// check (출력이 발생하는 부분)
			case 'c':
				scanf("%d", &number);

				// 숫자가 집합에 존재하는 경우
				if (number_check[number]) {
					printf("1\n");
				}
				// 집합에 존재하지 않는 경우
				else {
					printf("0\n");
				}

				break;

			// toggle
			case 't':
				scanf("%d", &number);

				// toggle 연산 수행
				number_check[number] = 1 - number_check[number];

				break;

			// empty
			case 'e':
				empty();
		}
	}

	return 0;
}

void all() {
	for (int i = 1; i <= 20; i++) {
		number_check[i] = 1;
	}
}

void empty() {
	for (int i = 1; i <= 20; i++) {
		number_check[i] = 0;
	}
}