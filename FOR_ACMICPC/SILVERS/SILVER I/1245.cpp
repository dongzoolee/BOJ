#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
using ll = long long;
int arr[102][72], n, m, cnt = 0;
bool chk[102][72] = { 0 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
void bfs() {
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			if (chk[i][f]) continue;
			bool no = 0;
			deque<pair<int, int>>q;
			q.push_back({ i,f });
			chk[i][f] = 1;
			if (!arr[i][f]) continue; // 0Àº °É·¯
			int og = arr[i][f];
			while (!q.empty()) {
				int xx = q.front().second, yy = q.front().first, xy = arr[yy][xx];
				q.pop_front();

				for (int x = 0; x < 8; x++) {
					if (yy + dy[x] < 0 || yy + dy[x] >= n || xx + dx[x] < 0 || xx + dx[x] >= m) continue;
					if (chk[yy + dy[x]][xx + dx[x]]) continue;

					if (arr[yy + dy[x]][xx + dx[x]] > xy && og >= arr[yy + dy[x]][xx + dx[x]]) {

					}
					if (arr[yy + dy[x]][xx + dx[x]] > xy && og < arr[yy + dy[x]][xx + dx[x]]) {
						no = 1;
					}
					if (arr[yy + dy[x]][xx + dx[x]] <= xy) {
						chk[yy + dy[x]][xx + dx[x]] = 1;
						q.push_back({ yy + dy[x], xx + dx[x] });
					}
				}
				if (no == 0 && q.empty())
					cnt++;
			} // end of while
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> arr[i][f];

	bfs();
	cout << cnt;
}