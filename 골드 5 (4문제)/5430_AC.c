// 설명 링크 : https://moon-gd.tistory.com/82
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char p[100001];
int X[100000], front, rear, size;

void handling();

int main() {
	int T = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", p);
		scanf("%d ", &size);
		getchar();
		for (int j = 0; j < size; j++) {
			scanf("%d", &X[j]);
			getchar();
		}
		if (size == 0)
			getchar();

		handling();
	}
	return 0;
}

void handling() {
	int len = strlen(p), dir = 1;

	front = 0;
	rear = size - 1;
	for (int i = 0; i < len; i++) {
		if (p[i] == 'R')
			dir *= -1;
		else {
			if (front > rear) {
				printf("error\n");
				return;
			}
			if (dir == 1)
				front++;
			else
				rear--;
		}
	}

	printf("[");
	if (dir == 1) {
		for (; front <= rear; front++) {
			printf("%d", X[front]);
			if (front != rear)
				printf(",");
		}
	}
	else {
		for (; rear >= front; rear--) {
			printf("%d", X[rear]);
			if (rear != front)
				printf(",");
		}
	}
	printf("]\n");
}