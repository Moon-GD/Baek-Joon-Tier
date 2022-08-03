#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

// ���� ���� ����
int network[MAX][MAX];  // ���� ����
int visited[MAX];  // �湮 ����
int stack[MAX * MAX], top = -1;  // ����

// �Լ� ���� ����
int stack_pop();

int main() {
	int pc, connect;
	scanf("%d %d", &pc, &connect);

	int com1, com2;
	for (int i = 0; i < connect; i++) {
		scanf("%d %d", &com1, &com2);

		// ���� ���� ����
		network[com1][com2]++;
		network[com2][com1]++;
	}

	stack[++top] = 1;

	int temp;  // �ӽ� ���� ����
	int count = 0;  // ������ PC ���� ���� ����
	while (1) {
		temp = stack_pop();
		// ���� ���� : ���ÿ��� ���� �� ���� ���
		if (temp == -1) {
			break;
		}

		// �湮�� �� ���� ���
		if (visited[temp] == 0) {
			visited[temp] = 1;
			count++;
		}

		for (int i = 1; i <= pc; i++) {
			// ����Ǿ� ���� ���
			if (network[temp][i]) {
				// �湮�� ���� �ִ� ��� continue
				if (visited[i]) {
					continue;
				}
				// �湮�� ���� ���� ���
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
	// ���ÿ��� �� �̻� �� �� ���� ��� -1�� ��ȯ
	if (top == -1) {
		return -1;
	}

	// ���� �� ���� �ִ� ��ǻ�� ���� ��ȯ
	return stack[top--];
}