// ���� ��ũ : https://moon-gd.tistory.com/67
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int parent[MAX];  // �θ� ���� ����
int count[MAX];  // ��� ���� ����
int visited[MAX];  // �湮 ����

void union_parent(int a, int b);
int find_parent(int v);

int main() {
	// �ӽ� ���� ����
	int i, v1, v2;

	// �׷��� ���� �Է� �ޱ�
	int vertex, edge;
	scanf("%d %d", &vertex, &edge);

	// �θ� ���� �ʱ�ȭ + ��� ���� ����
	for (i = 1; i <= vertex; i++) {
		parent[i] = i;
		count[i] = 1;
	}

	// �Է� + Union
	for (i = 0; i < edge; i++) {
		scanf("%d %d", &v1, &v2);
		union_parent(v1, v2);
	}

	// ���� ��� ����
	int component = 0;
	for (i = 1; i <= vertex; i++) {
		// ��尡 �޷��ִ� ������ �˻�
		if (count[i]) {
			// �ش� ��� �θ� ��ȣ ã��
			int parent_i = find_parent(i);

			// �˻����� ���� �θ� ����
			if (visited[parent_i] == 0) {
				// �˻� ���� ����� ���� ���� + 1
				visited[parent_i] = 1;
				component++;
			}
		}
	}

	// ���� ��� ���� ���
	printf("%d", component);

	return 0;
}

void union_parent(int a, int b) {
	int parent_a = find_parent(a);
	int parent_b = find_parent(b);

	// ���� �Ҽ��̸� return
	if (parent_a == parent_b) {
		return;
	}

	// a ��尡 �� ���� ���
	if (count[parent_a] > count[parent_b]) {
		parent[b] = parent_a;
		count[b] = 0;
		count[a]++;
	}
	// b ��尡 �� ���� ���
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