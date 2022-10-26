// 설명 링크 : https://moon-gd.tistory.com/95
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100 + 1
#define QUEUE_SIZE 10000
#include <stdio.h>

// 그림	정보 저장할 구조체 선언
typedef struct node {
	int isVisited;
	char color;
	char type;
}node;
node grids[MAX][MAX] = { 0 };

// BFS 탐색을 위한 Queue 선언
typedef struct pos_node {
	int x;
	int y;
}pos_node;
pos_node queue[QUEUE_SIZE];

// Queue 변수 선언
int front = 0, rear = 0;

// Queue 관련 함수 선언
void push(int i, int j);
pos_node pop();

// 방향 배열 선언
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

// BFS 함수
void BFS();
void BFS_type();

// 그림 크기
int size;

// 반복문 임시 변수 선언
int i, j, k;
char temp_c;

// 정답 변수
int goal = 0;
int goal_type = 0;

int main() {
	// 그림 크기 입력
	scanf("%d", &size);

	// 공백 처리
	scanf("%c", &temp_c);

	// 그림 정보 입력
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%c", &grids[i][j].color);

			// 적록색약 처리
			if (grids[i][j].color == 'B') {
				grids[i][j].type = 'X';
			}
			else {
				grids[i][j].type = 'Y';
			}
		}
		scanf("%c", &temp_c);
	}

	// BFS 탐색
	BFS();

	// BFS_type 탐색
	BFS_type();
	
	printf("%d %d", goal, goal_type);

	return 0;
}

void push(int i, int j) {
	pos_node temp_pos_node = { i, j };
	rear = (rear + 1) % QUEUE_SIZE;
	queue[rear] = temp_pos_node;
}

pos_node pop() {
	front = (front + 1) % (QUEUE_SIZE);
	return queue[front];
}

void BFS() {
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// Continue : 방문한 칸
			if (grids[i][j].isVisited) {
				continue;
			}
			// 방문하지 않은 경우
			else {
				// 시작 색깔 선정
				char start_color = grids[i][j].color;

				// 큐 인덱스 초기화
				front = rear = 0;

				push(i, j);
				grids[i][j].isVisited = 1;
				goal += 1;

				// 큐가 빌 때까지
				while (front != rear) {
					pos_node pos = pop();

					for (k = 0; k < 4; k++) {
						int new_x = pos.x + dir_x[k];
						int new_y = pos.y + dir_y[k];

						// Continue : X 허용 범위를 벗어난 경우
						if (0 > new_x || new_x >= size) {
							continue;
						}

						// Continue : Y 허용 범위를 벗어난 경우
						if (0 > new_y || new_y >= size) {
							continue;
						}
						
						// Continue : 이미 방문한 경우
						if (grids[new_x][new_y].isVisited) {
							continue;
						}

						if (grids[new_x][new_y].color == start_color) {
							push(new_x, new_y);
							grids[new_x][new_y].isVisited = 1;
						}
					}
				}
			}
		}
	}


}

void BFS_type() {
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// Continue : 방문한 칸
			// 이 때는 isVisited = 0일 때가 방문한 칸
			if (grids[i][j].isVisited == 0) {
				continue;
			}
			// 방문하지 않은 경우
			else {
				// 시작 색깔 선정
				char start_type = grids[i][j].type;

				// 큐 인덱스 초기화
				front = rear = 0;

				push(i, j);
				grids[i][j].isVisited = 0;
				goal_type += 1;

				// 큐가 빌 때까지
				while (front != rear) {
					pos_node pos = pop();

					for (k = 0; k < 4; k++) {
						int new_x = pos.x + dir_x[k];
						int new_y = pos.y + dir_y[k];

						// Continue : X 허용 범위를 벗어난 경우
						if (0 > new_x || new_x >= size) {
							continue;
						}

						// Continue : Y 허용 범위를 벗어난 경우
						if (0 > new_y || new_y >= size) {
							continue;
						}

						// Continue : 이미 방문한 경우
						if (grids[new_x][new_y].isVisited == 0) {
							continue;
						}

						if (grids[new_x][new_y].type == start_type) {
							push(new_x, new_y);
							grids[new_x][new_y].isVisited = 0;
						}
					}
				}
			}
		}
	}
}