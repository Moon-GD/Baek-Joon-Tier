// 설명 링크 : https://moon-gd.tistory.com/80
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

typedef struct node {
	int x;
	int y;
	int z;
	int day;
}node;
node queue[MAX * MAX * MAX];

// 큐 관련 함수
int front = 0, rear = 0;
void enque(int, int, int, int);
node deque();

int tomatoes[MAX][MAX][MAX];  // 토마토 상자 배열
int visited[MAX][MAX][MAX];  // 방문 배열

// 이동 관련 방향 배열
int dir_x[6] = { 0, 0, 0, 1, 0, -1 };
int dir_y[6] = { 0, 0, -1, 0, 1, 0 };
int dir_z[6] = { 1, -1, 0, 0, 0, 0 };

int main() {
	// 반복문 순회를 위한 임시 전역 변수
	int i, j, k;

	// 토마토 상자 크기 확인
	int x_size, y_size, z_size;
	scanf("%d %d %d", &x_size, &y_size, &z_size);

	// 공간 정보 체크를 위한 변수
	int total_size, colored_size = 0, empty_size = 0;
	total_size = x_size * y_size * z_size;

	// 상자 정보 입력 받기
	for (k = 0; k < z_size; k++) {
		for (j = 0; j < y_size; j++) {
			for (i = 0; i < x_size; i++) {
				scanf("%d", &tomatoes[i][j][k]);

				// 토마토가 있는 칸인 경우
				if (tomatoes[i][j][k] == 1) {
					// 큐에 넣어주고 방문 정보 체크
					enque(i, j, k, 0);
					visited[i][j][k] = 1;
				}
				// 빈 칸인 경우
				else if (tomatoes[i][j][k] == -1) {
					// 빈 영역 ++
					empty_size++;
				}
			}
		}
	}

	// 색칠 영역 ++
	colored_size = rear;

	while (front != rear) {
		// 큐에서 익은 토마토 정보 하나 빼기
		node temp = deque();

		int cur_x = temp.x;
		int cur_y = temp.y;
		int cur_z = temp.z;
		int cur_day = temp.day;

		for (i = 0; i < 6; i++) {
			int new_x = cur_x + dir_x[i];
			int new_y = cur_y + dir_y[i];
			int new_z = cur_z + dir_z[i];

			// X 범위 유효성 검사
			if (new_x < 0 || new_x >= x_size) {
				continue;
			}

			// Y 범위 유효성 검사
			if (new_y < 0 || new_y >= y_size) {
				continue;
			}

			// Z 범위 유효성 검사
			if (new_z < 0 || new_z >= z_size) {
				continue;
			}

			// 이미 방문한 곳인 경우
			if (visited[new_x][new_y][new_z]) {
				continue;
			}

			// 빈 칸인 경우
			if (tomatoes[new_x][new_y][new_z] == -1) {
				continue;
			}

			// 위의 반례에 모두 해당하지 않는 경우
			// 즉, 익지 않은 새로운 토마토를 찾았을 경우
			enque(new_x, new_y, new_z, cur_day + 1);

			// 색칠 영역 추가 + 방문 정보 체크
			colored_size++;
			visited[new_x][new_y][new_z] = 1;
		}
	}

	if (colored_size + empty_size == total_size) {
		if (colored_size) {
			printf("%d", queue[rear - 1].day);
		}
		else {
			printf("0");
		}
	}
	else {
		printf("-1");
	}

	return 0;
}

void enque(int x, int y, int z, int day) {
	node temp = { x, y, z, day };
	queue[rear++] = temp;
}

node deque() {
	return queue[front++];
}