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
int arr[100][100];
int ylen = 3, xlen = 3;
void r_() {
	for (int f = 0; f < ylen && f<100; f++) {
		int newone[100] = { 0 };
		int idx = 0;
		vector<pair<int, int>>tmp(101, { 0,0 });
		for (int z = 0; z < 101; z++) tmp[z].first = z;
		for (int i = 0; i < 100; i++) {
			tmp[arr[f][i]].second++;
		}
		sort(tmp.begin(), tmp.end(), [](auto a, auto b) {
			if (a.second == b.second)
				return a.first < b.first;
			else
				return a.second < b.second;
		});
		for (int h = 1; h < 101; h++) {
			if (tmp[h].second != 0 && tmp[h].first != 0) {
				newone[idx++] = tmp[h].first;
				if (idx == 100) break;
				newone[idx++] = tmp[h].second;
				if (idx == 100) break;
			}
		}
		memcpy(arr[f], newone, 100 * sizeof(int));
		xlen = max(xlen, idx);
	}
}
void c_() {
	for (int f = 0; f < xlen && f<100; f++) {
		vector<pair<int, int>>tmp(101, { 0,0 });
		for (int z = 0; z < 101; z++) tmp[z].first = z;
		for (int i = 0; i < 100; i++) {
			tmp[arr[i][f]].second++;
		}
		sort(tmp.begin(), tmp.end(), [](auto a, auto b) {
			if (a.second == b.second)
				return a.first < b.first;
			else
				return a.second < b.second;
		});
		int idx = 0;
		for (int h = 1; h < 101; h++) {
			if (tmp[h].second != 0 && tmp[h].first != 0) {
				arr[idx++][f] = tmp[h].first;
				if (idx == 100) break;
				arr[idx++][f] = tmp[h].second;
				if (idx == 100) break;
			}
		}
		for (int h = idx; h < 100; h++)
			arr[h][f] = 0;
		ylen = max(ylen, idx);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int f = 0; f < 3; f++)
			cin >> arr[i][f];

	if (arr[r - 1][c - 1] == k) { cout << 0; return 0; }
	int cnt = 0;
	while (1) {
		if (ylen >= xlen) {
			r_();
			cnt++;
			if (arr[r - 1][c - 1] == k)
				break;
		}
		if (cnt >= 100) { cout << -1; return 0; }
		if (ylen < xlen) {
			c_();
			cnt++;
			if (arr[r - 1][c - 1] == k)
				break;
		}
		if (cnt >= 100) { cout << -1; return 0; }
	}
	cout << cnt;
}