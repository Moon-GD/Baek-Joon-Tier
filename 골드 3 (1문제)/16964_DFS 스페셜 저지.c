// 설명 링크 : https://moon-gd.tistory.com/98
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef struct node* nodePointer;
typedef struct node {
	int value;
	nodePointer next;
}node;
node graph[MAX] = { 0, NULL };

int visited[MAX];
int input_order[MAX];
int depth[MAX];
int child[MAX];

void insert(int start, int end);
int dfs(int start, int count);

int main() {
	int size = 0;
	int v1, v2; // 정점 임시 변수

	// 입력
	scanf("%d", &size);
	for (int i = 1; i < size; i++) {
		scanf("%d %d", &v1, &v2);
		insert(v1, v2);
		insert(v2, v1);
	}

	dfs(1, 0);

	for (int i = 1; i <= size; i++) {
		scanf("%d", &input_order[i]);
	}

	if (input_order[1] != 1) { printf("0"); return 0; }

	for (int i = 2; i <= size; i++) {
		if (i + child[input_order[i]] > size) {
			continue;
		}

		int next_depth = depth[input_order[i + child[input_order[i]]]];

		if (next_depth > depth[input_order[i]]) {
			printf("0");
			return 0;
		}
	}

	printf("1");

	return 0;
}

void insert(int start, int end) {
	nodePointer temp = (nodePointer)malloc(sizeof(node));
	temp->next = NULL;
	temp->value = end;

	if (graph[start].next) {
		temp->next = graph[start].next;
		graph[start].next = temp;
	}
	else {
		graph[start].next = temp;
	}
}

int dfs(int start, int count) {
	if (visited[start] == 1) {
		return 0;
	}
	else {
		visited[start] = 1;
		depth[start] = count;
		nodePointer searcher = graph[start].next;
		int child_count = 1;

		for (; searcher; searcher = searcher->next) {
			if (visited[searcher->value] == 0) {
				child_count += dfs(searcher->value, count + 1);
			}
		}

		return child[start] = child_count;
	}
}