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

int main() {
	long long N, arr[6], min_1 = INT_MAX, min_2 = INT_MAX, min_3 = INT_MAX, result = 0;
	cin >> N;

	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	if (N == 1) {
		sort(arr, arr + 6);
		for (int i = 0; i < 5; i++)
			result += arr[i];
		cout << result;
		return 0;
	}

	for (int i = 0; i < 6; i++)
		min_1 = min(min_1, arr[i]);

	min_2 = min(min_2, arr[0] + arr[3]);
	min_2 = min(min_2, arr[3] + arr[5]);
	min_2 = min(min_2, arr[5] + arr[2]);
	min_2 = min(min_2, arr[2] + arr[0]);
	min_2 = min(min_2, arr[3] + arr[1]);
	min_2 = min(min_2, arr[1] + arr[2]);
	min_2 = min(min_2, arr[2] + arr[4]);
	min_2 = min(min_2, arr[4] + arr[3]);
	min_2 = min(min_2, arr[0] + arr[1]);
	min_2 = min(min_2, arr[1] + arr[5]);
	min_2 = min(min_2, arr[5] + arr[4]);
	min_2 = min(min_2, arr[4] + arr[0]);

	min_3 = min(min_3, arr[0] + arr[3] + arr[4]);
	min_3 = min(min_3, arr[0] + arr[1] + arr[3]);
	min_3 = min(min_3, arr[0] + arr[1] + arr[2]);
	min_3 = min(min_3, arr[0] + arr[2] + arr[4]);
	min_3 = min(min_3, arr[1] + arr[3] + arr[5]);
	min_3 = min(min_3, arr[1] + arr[2] + arr[5]);
	min_3 = min(min_3, arr[2] + arr[4] + arr[5]);
	min_3 = min(min_3, arr[3] + arr[4] + arr[5]);

	result = min_1 * (4 * (N - 2) + 5 * (long long)pow(N - 2, 2)) + min_2 * 4 * (2 * N - 3) + min_3 * 4;
	cout << result;
}