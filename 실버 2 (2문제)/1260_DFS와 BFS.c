// ���� ��ũ : https://moon-gd.tistory.com/60
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTEX 1001
#define MAX_EDGE 10000

int connect[MAX_VERTEX][MAX_VERTEX];
int visited[MAX_VERTEX];
int stack[MAX_EDGE];
int queue[MAX_EDGE];

int vertex, edge, start, top = 0;
int front = 0, rear = 0;

void dfs(int);

int main() {

	// �Է� �ޱ�
	scanf("%d %d %d", &vertex, &edge, &start);
	int v1, v2, i;
	for (i = 0; i < edge; i++) {	
		scanf("%d %d", &v1, &v2);

		// ���� ���� ����
		connect[v1][v2] = 1;
		connect[v2][v1] = 1;
	}

	// dfs
	// ��� Ȱ��
	dfs(start);
	putchar('\n');

	// bfs
	// queue Ȱ��
	// �� �����ʹ� �湮 �迭�� �ǹ̰� �ݴ�� ����
	// 0 : �湮,  1 : �湮 X
	
	// queue�� ������ ���� + ������ �湮 ǥ��
	queue[front++] = start;
	visited[start] = 0;

	while (front > rear) {
		v2 = queue[rear++];

		printf("%d ", v2);
		
		for (i = 1; i <= vertex; i++) {
			// ����Ǿ��ִ� �����̸�, �湮���� ���� ���
			if (connect[v2][i] && visited[i]) {
				// ť ���� + �湮 ǥ��
				queue[front++] = i;
				visited[i] = 0;
			}
		}
	}

	return 0;
}

void dfs(int v) {
	// �湮 ǥ��
	visited[v] = 1;

	// ���
	printf("%d ", v);

	for (int i = 1; i <= vertex; i++) {
		if (connect[v][i] && visited[i] == 0) {
			dfs(i);
		}
	}
}