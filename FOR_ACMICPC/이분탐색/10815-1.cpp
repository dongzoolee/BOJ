#include <stdio.h>
int card_num, cards[500001], mycard_num, mycards[500001], tmp[500001];

void merge(int arr[], int start, int end) {
    if (start == end) return;
    int m = (start + end) / 2;
    int idx = start, idxl = 0, idxr = start;
    int size = 0;
    merge(arr, start, m);
    merge(arr, m + 1, end);
    while (idxr <= m)
        tmp[size++] = arr[idxr++];
    while (idxl < size && idxr <= end)
        arr[idx++] = (tmp[idxl] < arr[idxr]) ? tmp[idxl++] : arr[idxr++];
    while (idxl < size)
        arr[idx++] = tmp[idxl++];
}

int binary(int arr[], int target, int length) {
    int low = 0;
    int high = length-1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main(void) {
	scanf("%d", &card_num);
	for (int i = 0; i < card_num; i++)
		scanf("%d", &cards[i]);
    merge(cards, 0, card_num - 1);

	scanf("%d", &mycard_num);
	for (int i = 0; i < mycard_num; i++) {
		scanf("%d", &mycards[i]);
        printf("%d ", binary(cards, mycards[i], card_num));
	}
}