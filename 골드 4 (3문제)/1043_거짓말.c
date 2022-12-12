// 설명 링크 : https://moon-gd.tistory.com/133
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 51

// 사람 수, 파티 수, 진실을 아는 사람 수
int person_number, party_number, know_true_number;

int party[MAX][MAX];

// 진실을 아는 사람 정보
// 값이 1인 경우 : 진실을 아는 사람
// 값이 0인 경우 : 진실을 모르는 사람
int know_true[MAX];

// 진실을 알게 된 사람 정보를 갱신해주는 함수
// 새롭게 진실을 알게 된 사람이 생긴 경우 : return 1
// 이전과 같은 경우 : return 0
int update();

int main() {
	// 입력 : 사람 수, 파티 수, 진실을 아는 사람 수
	scanf("%d %d %d", &person_number, &party_number, &know_true_number);

	// 입력 : 진실을 아는 사람 정보
	int temp_num;
	for (int i = 0; i < know_true_number; i++) {
		scanf("%d", &temp_num);
		know_true[temp_num] = 1;
	}

	// 입력 : 파티 인원 수, 파티 참여 인원
	for (int i = 0; i < party_number; i++) {
		scanf("%d", &party[i][0]);

		for (int j = 1; j <= party[i][0]; j++) {
			scanf("%d", &party[i][j]);
		}
	}

	// 변경이 발생하지 않을 경우 while문 탈출
	do {
	} while (update());

	// 결과 계산
	int count = 0;
	for (int i = 0; i < party_number; i++) {
		// 파티 인원이 0이 아니라면? update() 함수의 영향을 받지 않았음을 의미
		// 이는 파티 인원이 모두 진실을 모른다는 것을 의미!
		// 따라서 count에 1을 더해준다
		if (party[i][0]) {
			count++;
		}
	}

	// 결과 출력
	printf("%d", count);

	return 0;
}

// 진실을 알게 된 사람 정보를 갱신해주는 함수
// 새롭게 진실을 알게 된 사람이 생긴 경우 : return 1
// 이전과 같은 경우 : return 0
int update() {
	int changed = 0;
	for (int i = 0; i < party_number; i++) {
		int flag = 0;
		for (int j = 1; j <= party[i][0]; j++) {
			if (know_true[party[i][j]]) {
				flag = 1;
				break;
			}
		}

		if (flag) {
			for (int j = 1; j <= party[i][0]; j++) {
				if (know_true[party[i][j]] == 0) {
					know_true[party[i][j]] = 1;
					changed = 1;
				}
			}
			party[i][0] = 0;
		}
	}

	return changed;
}