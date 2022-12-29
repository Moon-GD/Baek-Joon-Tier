// 설명 링크 : https://moon-gd.tistory.com/142
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001

// declare : heap array
int heap[MAX];

// initialize : heap size
int heap_size = 0;

// exchange a and b
void swap(int* a, int* b);

// heap functions
void add(int number);
int delete_root();

int main() {
	// declare : number of operations
	int N = 0;

	// input : get number of operations
	scanf("%d", &N);

	// declare : for getting inputs
	int operation;

	for (int i = 1; i <= N; i++) {
		// input : get operation
		scanf("%d", &operation);

		// add to heap
		if (operation) {
			add(operation);
		}
		// delete root node
		else {
			printf("%d\n", delete_root());
		}
	}

	return 0;
}

// exchange a and b
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void add(int number) {
	// create : add new node to heap
	heap[++heap_size] = number;

	for (int i = heap_size; i > 1; i = i / 2) {
		// child node's key is bigger than root node's
		if (heap[i] > heap[i / 2]) {
			swap(&heap[i], &heap[i / 2]);
		}
		// break : new node find it's proper location
		else {
			break;
		}
	}
}

int delete_root() {
	// return 0 : empty heap
	if (heap_size == 0) {
		return 0;
	}
	// if heap is not empty
	else {
		// initialize : a variable that will be returned
		int root = heap[1];

		// update : swap root node and last node
		swap(&heap[1], &heap[heap_size]);

		// update : heap size
		heap_size--;

		for (int i = 1; i <= heap_size;) {
			// left & right child nodes exist
			if (i * 2 + 1 <= heap_size) {
				if (heap[i] >= heap[i * 2] && heap[i] >= heap[i * 2 + 1]) {
					break;
				}
				else {
					if (heap[i * 2] >= heap[i] && heap[i * 2] >= heap[i * 2 + 1]) {
						// update : swap left node and root node
						swap(&heap[i], &heap[i * 2]);

						// update : i
						i = i * 2;
					}
					else if (heap[i * 2 + 1] >= heap[i] && heap[i * 2 + 1] >= heap[i * 2]) {
						// update : swap right node and root node
						swap(&heap[i], &heap[i * 2 + 1]);

						// update : i
						i = i * 2 + 1;
					}
				}
			}
			// only left child node exists
			else if (i * 2 <= heap_size) {
				// left child's key is bigger than root node's
				if (heap[i * 2] >= heap[i]) {
					// update : swap left node and root node
					swap(&heap[i], &heap[i * 2]);

					// update : i
					i = i * 2;
				}
				else {
					break;
				}
			}
			// no child exists
			else {
				break;
			}
		}

		return root;
	}
}