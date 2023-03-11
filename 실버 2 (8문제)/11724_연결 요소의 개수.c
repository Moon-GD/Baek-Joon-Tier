// 참고 링크 : https://moon-gd.tistory.com/67
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int parent[MAX];  // 부모 정점 저장
int count[MAX];  // 노드 개수 저장
int visited[MAX];  // 방문 정보

void union_parent(int a, int b);
int find_parent(int v);

int main() {
	// 임시 정수 변수
	int i, v1, v2;

	// 그래프 정보 입력 받기
	int vertex, edge;
	scanf("%d %d", &vertex, &edge);

	// 부모 정보 초기화 + 노드 개수 저장
	for (i = 1; i <= vertex; i++) {
		parent[i] = i;
		count[i] = 1;
	}

	// 입력 + Union
	for (i = 0; i < edge; i++) {
		scanf("%d %d", &v1, &v2);
		union_parent(v1, v2);
	}

	// 연결 요소 개수
	int component = 0;
	for (i = 1; i <= vertex; i++) {
		// 노드가 달려있는 정점만 검사
		if (count[i]) {
			// 해당 노드 부모 번호 찾기
			int parent_i = find_parent(i);

			// 검색되지 않은 부모 노드면
			if (visited[parent_i] == 0) {
				// 검색 흔적 남기고 연결 개수 + 1
				visited[parent_i] = 1;
				component++;
			}
		}
	}

	// 연결 요소 개수 출력
	printf("%d", component);

	return 0;
}

void union_parent(int a, int b) {
	int parent_a = find_parent(a);
	int parent_b = find_parent(b);

	// 같은 소속이면 return
	if (parent_a == parent_b) {
		return;
	}

	// a 노드가 더 많은 경우
	if (count[parent_a] > count[parent_b]) {
		parent[b] = parent_a;
		count[b] = 0;
		count[a]++;
	}
	// b 노드가 더 많은 경우
	else {
		parent[a] = parent_b;
		count[a] = 0;
		count[b]++;
	}
}

int find_parent(int v) {
	if (parent[v] == v) {
		return v;
	}
	else {
		return parent[v] = find_parent(parent[v]);
	}
}