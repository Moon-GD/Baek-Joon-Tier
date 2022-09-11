// 설명 링크 : https://moon-gd.tistory.com/72
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 301

// 필요한 변수 선언
int dir_X[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dir_Y[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int size = 0;  // 체스판 크기
int cur_x, cur_y;  // 현재 위치 좌표
int goal_x, goal_y;  // 목표 위치 좌표
int visited[MAX_SIZE][MAX_SIZE];  // 방문 배열
int move_count = 0;

// Queue 배열을 위한 구조체
typedef struct node {
	int x;
	int y;
	int count;
}node;

node queue[MAX_SIZE * MAX_SIZE + 1];
int front = 0, rear = 0;  // Queue 인덱스 변수

// 필요 함수 선언
void initialize(int);  // 초기화 함수
void dfs();  // 너비 우선 탐색 함수
void enque(int x, int y, int count);  // Queue 삽입 함수
node deque();  // Queue 추출 함수

int main() {
	int test_num = 0;
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++) {
		scanf("%d %d %d %d %d", &size, &cur_x, &cur_y, &goal_x, &goal_y);  // 필요 정보 입력 받기

		// 초기화
		initialize(size);

		enque(cur_x, cur_y, 0);
		dfs();
		printf("%d\n", move_count);
	}

	return 0;
}

void initialize(int length) {
	// 초기화 목록 : 
	// ① 방문 배열
	// ② 움직임 횟수 = 0
	// ③ queue 인덱스 변수

	int i, j;

	// ① 방문 배열 초기화
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			visited[i][j] = 0;
		}
	}

	// ② 움직임 횟수 = 0 으로 설정
	move_count = 0;

	// ③ queue 인덱스 변수 초기화
	front = 0;
	rear = 0;
}

void dfs() {
	while (1) {
		node temp = deque();
		int x = temp.x;
		int y = temp.y;
		int count = temp.count;

		// 목적지에 도달한 경우
		if (x == goal_x && y == goal_y) {
			move_count = count;
			return;
		}

		// 움직임이 가능한 8개의 방향 순회
		for (int i = 0; i < 8; i++) {
			int new_x = x + dir_X[i];
			int new_y = y + dir_Y[i];

			// X 허용 범위를 벗어난 경우 1
			if (new_x < 0 || new_x >= size) {
				continue;
			}

			// Y 허용 범위를 벗어난 경우 2
			if (new_y < 0 || new_y >= size) {
				continue;
			}

			// 이미 방문한 곳의 경우
			if (visited[new_x][new_y]) {
				continue;
			}

			// 위의 예외 사항에 해당하지 않는 경우 Queue에 삽입
			enque(new_x, new_y, count + 1);

			// Enque한 좌표 방문 배열에 기록
			visited[new_x][new_y] = 1;
		}
	}
}

void enque(int x, int y, int count) {
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].count = count;
	rear++;
}

node deque() {
	return queue[front++];
}