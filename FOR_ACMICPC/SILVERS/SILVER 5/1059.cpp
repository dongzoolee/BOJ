#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int h, L, arr[52], N, i = 0;

int avail(int target) {
	while (arr[i++] <= target) {}
	if (arr[i - 2] == target) {
		i -= 2;
		return 1;
	}
	else {
		i--;
		return 0;
	}
}

int main() {
	cin >> L;

	for (int i = 0; i < L; i++)
		cin >> arr[i];
	cin >> N;

	sort(arr, arr + L);

	if (avail(N) == 1) // Ã£À½
		cout << "0";
	else if (i != 0)
		cout << (arr[i] - N - 1) + (N - arr[i - 1] - 1) * (arr[i] - N);
	else
		cout << (arr[i] - N - 1) + (N - 1) * (arr[i] - N);
}