// 설명 링크 : https://moon-gd.tistory.com/105
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>  // abs

int get_length(int num);  // 정수 Digit 자릿수 반환 함수


int main() {
	int target_channel = 0;  // 목표 채널
	int err_size = 0;  // 고장난 버튼 개수
	int buttons[10] = { 0 };  // 0 : 정상, 1 : 고장
	int temp_num = 0; // 임시 정수 변수
	int count = 0;

	scanf("%d %d", &target_channel, &err_size);
	for (int i = 0; i < err_size; i++) {
		scanf("%d", &temp_num);
		buttons[temp_num]++;
	}

	// Finish : 목표 채널이 100번인 경우
	if (target_channel == 100) {
		printf("0");
		return 0;
	}
	// 아닌 경우 count 변수 초기화
	else {
		count = abs(100 - target_channel);
	}

	int flag = 0;
	for (int i = 0; i <= 1000000; i++) {
		temp_num = i;
		flag = 0;
		
		do {
			// 숫자 중 고장난 버튼이 포함되어 있는 경우
			if (buttons[temp_num % 10]) {
				flag = 1;
				break;
			}
			else {
				temp_num /= 10;
			}
		} while (temp_num);
		
		// 현재 리모컨으로 갈 수 있는 번호인 경우
		if (flag == 0) {
			// 숫자 길이 계산
			int length = get_length(i);
			length = length < abs(100 - i) ? length : abs(100 - i);
			
			count = count < abs(i - target_channel) + length ? count : abs(i - target_channel) + length;

			if (i > target_channel) {
				break;
			}
		}
	}

	// 결과 출력
	printf("%d", count);

	return 0;
}

int get_length(int num) {
	// 한 자리 수인 경우
	if (0 <= num && num < 9) {
		return 1;
	}
	// 두 자리 이상인 경우
	else {
		int length = 0;
		while (num) {
			length++;
			num /= 10;
		}

		// 길이 반환
		return length;
	}
}