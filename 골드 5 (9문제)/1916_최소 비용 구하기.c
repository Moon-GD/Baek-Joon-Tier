// 설명 링크 : https://moon-gd.tistory.com/140
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc, free
#define MAX_CITY 1001
#define MAX_BUS 100000
#define INF 999999999

// declare : number of bus and city, respectively
int bus, city;

// declare : start point, end point
int target_start, target_end;

// declare : structure for linked lists
typedef struct node* node_pointer;
typedef struct node {
	int vertex;
	int cost;
	node_pointer next;
}node;
node bus_info[MAX_CITY];

// declare : distances between cities
int distance[MAX_CITY];

// declare : array that records visited info
int visited[MAX_CITY];

// declare : linked lists functions
void add_node(int start, int end, int cost);

// declare : function that returns min(a, b)
int get_min(int a, int b);

int main() {
	scanf("%d %d", &city, &bus);

	// declare : variables for input
	int start, end, cost;
	for (int i = 1; i <= bus; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		
		// create : add new node from start to end
		add_node(start, end, cost);
	}

	scanf("%d %d", &target_start, &target_end);

	// initialize : distances
	for (int i = 1; i <= city; i++) {
		distance[i] = INF;
	}

	// initialize : distance of start place
	distance[target_start] = 0;

	// dijkstra
	int start_city = city + 1;
	for (int i = 1; i <= city; i++) {
		int min_distance = INF;

		for (int j = 1; j <= city; j++) {
			if (visited[j] == 0 && distance[j] < min_distance) {
				start_city = j;
				min_distance = distance[j];
			}
		}
		 
		visited[start_city] = 1;

		node_pointer searcher = &bus_info[start_city];
		for (; searcher; searcher = searcher->next) {
			if (distance[searcher->vertex] > distance[start_city] + searcher->cost) {
				distance[searcher->vertex] = distance[start_city] + searcher->cost;
			}
		}
	}

	printf("%d", distance[target_end]);

	return 0;
}

void add_node(int start, int end, int cost) {
	// create : new node from start to end
	node_pointer new_node = (node_pointer)malloc(sizeof(node));
	new_node->vertex = end;
	new_node->cost = cost;
	new_node->next = NULL;

	// if start place is empty
	if (bus_info[start].next == NULL) {
		bus_info[start].next = new_node;
	}
	else {
		node_pointer searcher = &bus_info[start];

		for (; searcher->next; searcher = searcher->next) {
			if (searcher->vertex == end) {
				// update : if vertex(end) is already exists
				searcher->cost = get_min(searcher->cost, cost);

				// free 
				free(new_node);

				return;
			}
		}

		searcher->next = new_node;
	}
}

int get_min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}