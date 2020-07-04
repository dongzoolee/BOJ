#include <stdio.h>
#include <stdlib.h> // qsort 라이브러리
#define FLUSH while(getchar() != '\n')

typedef struct {
	int x;
	int y;
}xy;

int compare(const xy* first, const xy* second) {
	if (first->x == second->x)
		return first->y > second->y ? 1 : (first->y < second->y ? -1 : 0);
	else
		return first->x > second->x ? 1 : (first->x < second->x ? -1 : 0);
}

int main(void) {
	int N, i, j;
	scanf("%d", &N);
	xy* arr = (xy*)malloc(sizeof(xy) * N); // type == struct 배열
	for (i = 0; i < N; i++)
		scant("%d %d", arr[i].x, arr[i].y);

	qsort(arr, N, sizeof(xy), compare);

	for (i = 0; i < N; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}