#include <iostream>
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
using ll = long long;
int arr[10][10], length = -1, n;

void settingarr() {
	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	for (int f = 1; f < 10; f++)
		for (int i = f; i < 10; i++) {
			if (i == f) arr[f][i] = 1;
			else arr[f][i] = arr[f ][i-1] + arr[f - 1][i - 1];
		}
}

void judge(int len) {
	//if (n == 1 && len == 0) { cout << 0; return; }

	if (len == 0) {
		for (int i = 1; i < 10; i++) {
			if (n - arr[0][i] > 0)
				n -= arr[0][i];
			else if (n - arr[0][i] <= 0) {
				length = len;
				cout << i-1;
				return;
			}
		}
	}
	else
		for (int i = len; i < 10; i++) {
			if (n - arr[len][i] > 0)
				n -= arr[len][i];
			else if (n - arr[len][i] <= 0) {
				length = len;
				cout << i;
				return;
			}
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if (0<=n&&n <= 9) { cout << n; return 0; }
	if (n > 1022) { cout << -1; return 0; }
	settingarr();

	for (int i = 0; i < 10; i++) {
		judge(i);
		if (length != -1)
			break;
	}

	while (length > 0) {
		judge(--length);
	}
}