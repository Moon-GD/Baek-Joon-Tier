#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

// 변수 전역 공간
int network[MAX][MAX];  // 연결 정보
int visited[MAX];  // 방문 정보
int stack[MAX * MAX], top = -1;  // 스택

// 함수 전역 공간
int stack_pop();

int main() {
	int pc, connect;
	scanf("%d %d", &pc, &connect);

	int com1, com2;
	for (int i = 0; i < connect; i++) {
		scanf("%d %d", &com1, &com2);

		// 연결 정보 저장
		network[com1][com2]++;
		network[com2][com1]++;
	}

	stack[++top] = 1;

	int temp;  // 임시 정수 변수
	int count = 0;  // 감염된 PC 개수 세는 변수
	while (1) {
		temp = stack_pop();
		// 종료 조건 : 스택에서 빼낼 게 없을 경우
		if (temp == -1) {
			break;
		}

		// 방문한 적 없는 경우
		if (visited[temp] == 0) {
			visited[temp] = 1;
			count++;
		}

		for (int i = 1; i <= pc; i++) {
			// 연결되어 있을 경우
			if (network[temp][i]) {
				// 방문한 적이 있는 경우 continue
				if (visited[i]) {
					continue;
				}
				// 방문한 적이 없는 경우
				else {
					stack[++top] = i;
				}
			}
		}
	}

	printf("%d", count - 1);

	return 0;
}

int stack_pop() {
	// 스택에서 더 이상 뺄 게 없을 경우 -1을 반환
	if (top == -1) {
		return -1;
	}

	// 스택 맨 위에 있는 컴퓨터 정보 반환
	return stack[top--];
}