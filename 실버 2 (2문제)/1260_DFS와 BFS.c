// 참고 링크 : https://moon-gd.tistory.com/60
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

	// 입력 받기
	scanf("%d %d %d", &vertex, &edge, &start);
	int v1, v2, i;
	for (i = 0; i < edge; i++) {	
		scanf("%d %d", &v1, &v2);

		// 연결 정보 저장
		connect[v1][v2] = 1;
		connect[v2][v1] = 1;
	}

	// dfs
	// 재귀 활용
	dfs(start);
	putchar('\n');

	// bfs
	// queue 활용
	// 이 때부터는 방문 배열의 의미가 반대로 쓰임
	// 0 : 방문,  1 : 방문 X
	
	// queue에 시작점 삽입 + 시작점 방문 표시
	queue[front++] = start;
	visited[start] = 0;

	while (front > rear) {
		v2 = queue[rear++];

		printf("%d ", v2);
		
		for (i = 1; i <= vertex; i++) {
			// 연결되어있는 정점이며, 방문되지 않은 경우
			if (connect[v2][i] && visited[i]) {
				// 큐 삽입 + 방문 표시
				queue[front++] = i;
				visited[i] = 0;
			}
		}
	}

	return 0;
}

void dfs(int v) {
	// 방문 표시
	visited[v] = 1;

	// 출력
	printf("%d ", v);

	for (int i = 1; i <= vertex; i++) {
		if (connect[v][i] && visited[i] == 0) {
			dfs(i);
		}
	}
}