// 설명 링크 : https://moon-gd.tistory.com/97
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 15

int code_len, total_len;

int visited[26];
char spells[MAX];
char code[MAX];

// 임시 문자 변수
char temp_c;

void back_tracking(int len);
int code_validity();

int main() {	
	// 입력 받기
	scanf("%d %d", &code_len, &total_len);
	for (int i = 0; i < total_len; i++) {
		scanf("%c%c", &temp_c, &temp_c);
		visited[temp_c - 97] = 1;
	}

	// Count Sort 활용
	int j = 0;
	for (int i = 0; i < 26; i++) {
		if (visited[i]) {
			spells[j++] = i + 'a';
		}
	}

	back_tracking(0);

	return 0;
}

void back_tracking(int len) {
	// 코드가 완성되고, 유효성 검사도 통과한 경우
	if (len == code_len && code_validity()) {
		for (int i = 0; i < code_len; i++) {
			printf("%c", code[i]);
		}
		putchar('\n');
	}
	else {
		if (len) {
			for (int i = 0; i < total_len; i++) {
				if (code[len - 1] < spells[i]) {
					code[len] = spells[i];
					back_tracking(len + 1);
				}
			}
		}
		else {
			for (int i = 0; i < total_len; i++) {
				code[0] = spells[i];
				back_tracking(len + 1);
			}
		}
	}
}

int code_validity() {
	int consonant = 0;  // 자음 개수
	int collection = 0;  // 모음 개수

	for (int i = 0; i < code_len; i++) {
		if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u') {
			collection++;
		}
		else {
			consonant++;
		}
	}

	// Return 1 : 자음 2개, 모음 1개 이상인 경우
	if (consonant >= 2 && collection >= 1) {
		return 1;
	}
	// Return 0 : 자음이나 모음 개수가 충분하지 않은 경우
	else {
		return 0;
	}
}