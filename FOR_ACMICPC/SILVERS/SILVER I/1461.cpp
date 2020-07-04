#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int arr[10001];

int main() {
	int n, m, zero_pos = -1, counter = 0;
	cin >> n >> m;
	int z = n - 1, x = 0; // z는 우측 포인터, x는 좌측 포인터
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 1; i <= n; i++)
		if (arr[i - 1] < 0 && 0 < arr[i])
			zero_pos = i;

	if (zero_pos != -1) { // 한 가지 부호로만 이루어진 수열이 아니라면
		// 최대거리 처리단계
		if (abs(arr[0]) < abs(arr[n - 1])) { // 양수도 있고 음수도 있는거임
			if (arr[n - m] > 0) { // 앞에꺼가 양수라면
				counter += arr[n - 1];
				z -= m;
			}
			else { // 양수가 자기 혼자임
				counter += arr[n - 1];
				z = zero_pos - 1;
			}
		}
		else if (abs(arr[0]) > abs(arr[n - 1])) {
			if (arr[m - 1] < 0) { // 앞에꺼가 음수라면
				counter += -arr[0];
				x += m;
			}
			else { // 음수가 자기 혼자임
				counter += -arr[0];
				x = zero_pos;
			}
		}
		else { // 같을 경우
			if (zero_pos < n - zero_pos) {
				counter += arr[n - 1];
				z -= m;
			}
			else if (zero_pos > n - zero_pos) {
				counter += -arr[0];
				x += m;
			}
			else {
				counter += -arr[0];
				x += m;
			}
		}
	}
	else { // 한가지 부호로만 이루어진 수열이라면
		if (arr[0] < 0) {
			zero_pos = n;
			if (n == 1) {
				cout << -arr[0];
				return 0;
			}
			else {
				counter += -arr[0];
				x += m;
			}
		}
		else {
			zero_pos = 0;
			if (n == 1) {
				cout << arr[n - 1];
				return 0;
			}
			else {
				counter += arr[n - 1];
				z -= m;
			}
		}
	}

	while (zero_pos <= z) {
		if (zero_pos <= z - m + 1) {
			counter += arr[z] * 2;
		}
		else {
			counter += arr[z] * 2;
		}
		z -= m;
	}

	while (x < zero_pos) {
		if (x + m - 1 < zero_pos) {
			counter += -arr[x] * 2;
		}
		else {
			counter += -arr[x] * 2;
		}
		x += m;
	}
	cout << counter;
}