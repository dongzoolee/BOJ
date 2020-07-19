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
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
int arr[300][300];
int arr_[300][300];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int howmany() {
	int cnt = 0;
	bool chk[300][300] = { 0 };
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			if (chk[i][f] == 0 && arr[i][f] > 0) {
				q.push({ i,f });
				chk[i][f] = 1;
				while (!q.empty()) {
					for (int h = 0; h < 4; h++) {
						int y = q.front().first + dy[h], x = q.front().second + dx[h];
						if (y < 0 || y >= n || x < 0 || x >= m) continue;
						if (chk[y][x] == 1 || arr[y][x] <= 0) continue;

						q.push({ y,x });
						chk[y][x] = 1;
					}
					q.pop();
				}
				cnt++;
			}
		}
	return cnt;
}
int to_minus(int u, int v) {
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		if (arr[u + dy[i]][v + dx[i]] <= 0)
			cnt++;
	return cnt;
}
int bfs() {
	int cnt = 0;
	bool chk[300][300] = { 0 };
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			if (chk[i][f] == 0 && arr[i][f] > 0) {
				q.push({ i,f });
				chk[i][f] = 1;
				while (!q.empty()) {
					arr_[q.front().first][q.front().second] -= to_minus(q.front().first, q.front().second);
					for (int h = 0; h < 4; h++) {
						int y = q.front().first + dy[h], x = q.front().second + dx[h];
						if (y < 0 || y >= n || x < 0 || x >= m) continue;
						if (chk[y][x] == 1 || arr[y][x] <= 0) continue;

						q.push({ y,x });
						chk[y][x] = 1;
					}
					q.pop();
				}
				cnt++;// ÃÊ ¼¼±â
				memcpy(arr, arr_, sizeof(int) * 90000);
			}
		}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];
	memcpy(arr_, arr, sizeof(int) * 90000);
	int cnt = 0;
	if (howmany() >= 2) { cout << 0; return 0; }
	while (1) {
		cnt += bfs();
		int b = howmany();
		if (b >= 2) { cout << cnt; return 0; }
		if (b == 0) break;
	}
	cout << 0;
}