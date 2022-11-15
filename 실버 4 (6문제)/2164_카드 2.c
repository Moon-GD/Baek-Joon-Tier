// 설명 링크 : https://moon-gd.tistory.com/103
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 500001

int queue[MAX];
int front = 0, rear = 0;

void enque(int num);
int deque();

int main() {
	int size = 0;
	scanf("%d", &size);

	for (int i = 1; i <= size; i++) {
		enque(i);
	}

	while (rear - front != 1) {
		deque();
		enque(deque());
	}

	printf("%d", queue[front]);

	return 0;
}

void enque(int num) {
	rear %= MAX;
	queue[rear++] = num;
}

int deque() {
	front %= MAX;
	return queue[front++];
}