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
int arr[50][50], min_ = INT_MAX;

void tray(int y_idx, int x_idx) {
	int cnt_w = 0, cnt_b = 0;
	for (int i = y_idx; i < y_idx + 8; i++)
		for (int f = x_idx; f < x_idx + 8; f++) {
			if ((i + f) % 2 == 0) {
				if (arr[i][f] == 0)
					cnt_w++;
				else cnt_b++;
			}
			else {
				if (arr[i][f] == 0)
					cnt_b++;
				else
					cnt_w++;
			}
		}
	min_ = min(min_, cnt_b);
	min_ = min(min_, cnt_w);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			char a;
			cin >> a;
			if (a == 'W')
				arr[i][f] = 0;
			else
				arr[i][f] = 1;
		}
	for (int i = 0; i < n - 7; i++)
		for (int f = 0; f < m - 7; f++)
			tray(i, f);
	cout << min_;
}