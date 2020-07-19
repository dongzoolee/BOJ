#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <ctime>
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
int arr[501][501];
int mvx[4] = { 1,0,-1,0 };
int mvy[4] = { 0,-1,0,1 };
int n, m, cnt = 0;
int visited[501][501] = { 0 };
int dp[501][501] = { 0 };
// DFS에 dp를 섞어서 할 수 있다..
void dfs(pair<int, int>cur) {
	if (cur.first == n - 1 && cur.second == m - 1) { cnt++; return; } // 도달

	for (int i = 0; i < 4; i++) {
		int y = cur.first + mvy[i], x = cur.second + mvx[i];
		if (0 <= y && y < n && 0 <= x && x < m) {
			if (arr[cur.first][cur.second] > arr[y][x]) {
				dp[y][x] += dp[cur.first][cur.second];
				if (visited[y][x] == 0) {
					visited[y][x] = 1;
					dfs({ y, x });
					//visited[y][x] = 0;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	pair<int, int>cur = { 0,0 };
	dp[0][0] = 1;
	dfs(cur);
	cout << dp[n-1][m-1];
}