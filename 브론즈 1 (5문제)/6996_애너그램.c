// 참고 링크 : https://moon-gd.tistory.com/34
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int is_same(char*, char*);

int main() {
	int n = 0;
	char A[100], B[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s %s", &A, &B);
		printf("%s & %s are ", A, B);
		if (is_same(A, B) == 0) {
			printf("NOT ");
		}
		printf("anagrams.\n");
	}


	return 0;
}

int is_same(char* A, char* B) {
	for (int i = 0; i < (int)strlen(A); i++) {
		for (int j = 0; j < (int)strlen(A); j++) {
			if (A[i] > A[j]) {
				char temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	for (int i = 0; i < (int)strlen(B); i++) {
		for (int j = 0; j < (int)strlen(B); j++) {
			if (B[i] > B[j]) {
				char temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}

	if (strcmp(A, B) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}