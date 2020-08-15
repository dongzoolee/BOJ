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
int arr[501][501];
int chk[501][501];
int todes[501][501];
int mvx[4] = { 1,0,-1,0 };
int mvy[4] = { 0,-1,0,1 };
int n, m, cnt = 0;
int endpnt;
void dfs(pair<int, int>cur) {
	if (cur.first == n - 1 && cur.second == m - 1) { cnt++; return; } // µµ´Þ

	for (int i = 0; i < 4; i++) {
		int y = cur.first + mvy[i], x = cur.second + mvx[i];
		if (y < 0 || y >= n || x < 0 || x >= m) continue;
		if (chk[y][x]) {
			cnt += todes[y][x];
			continue;
		}
		if (arr[y][x] < endpnt) continue;
		if (arr[cur.first][cur.second] <= arr[y][x]) continue;

		chk[y][x] = 1;
		dfs({ y, x });
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];
	endpnt = arr[n - 1][m - 1];

	pair<int, int>cur = { 0,0 };
	chk[cur.first][cur.second] = 1;
	dfs(cur);
	cout << cnt;
}