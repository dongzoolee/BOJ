#include <iostream>
#include <string>
#include <queue>
#include <tuple>
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
int arr[1000][1000];
int n, m, min_ = INT_MAX, cnt = 0;
int mvx[] = { 1,0,-1,0 };
int mvy[] = { 0,-1,0,1 };
bool chk[1000][1000] = { 0 };
// ?DP 합쳐서 풀기
// 최단거리다.....BFS로 풀어야지.......휴
/*void dfs(pair<int, int>cur, int wallcnt, int cnt) {
	if (wallcnt > 1) return;
	if (cur.first == n - 1 && cur.second == m - 1) {
		min_ = min(cnt, min_); return;
	}

	for (int i = 0; i < 4; i++) {
		int y = cur.first + mvy[i], x = cur.second + mvx[i];
		if (chk[y][x] == 1 || (arr[y][x] == 1 && wallcnt >= 1)) continue;

		if (0 <= y && y < n && 0 <= x && x < m) {
			// map 안에다 있는 전제 하에
			if (arr[y][x] == 1 && wallcnt == 0 && chk[y][x] == 0) {
				// 벽뚫기 (1회만가능)
				chk[y][x] = 1;
				dfs({ y,x }, wallcnt + 1, cnt + 1);
				chk[y][x] = 0;
			}
			else if (arr[y][x] == 0 && wallcnt <= 1 && chk[y][x] == 0) {
				chk[y][x] = 1;
				dfs({ y,x }, wallcnt, cnt + 1);
				chk[y][x] = 0;
			}
		}
	}
}
*/
int bfs() {
	queue<tuple<int, int, int>>q;
	q.push({ 0, 0, 0 });
	bool chk[1000][1000] = { 0 };
	while (!q.empty()) {
		int qsz = q.size();
		for (int f = 0; f < qsz; f++) {
			int fst = get<0>(q.front()), scd = get<1>(q.front()), wallcnt = get<2>(q.front());
			q.pop();
			if (fst == n - 1 && scd == m - 1) { return cnt; }
			for (int i = 0; i < 4; i++) {
				int y = fst + mvy[i], x = scd + mvx[i];
				if (chk[y][x] == 1 || (arr[y][x] == 1 && wallcnt == 1)) continue;

				if (0 <= y && y < n && 0 <= x && x < m) {
					if (arr[y][x] == 1 && wallcnt == 0 && chk[y][x] == 0) {
						chk[y][x] = 1;
						q.push({ y,x,1 });
					}
					if (arr[y][x] == 0 && wallcnt <= 1 && chk[y][x] == 0) {
						chk[y][x] = 1;
						q.push({ y,x,wallcnt });
					}
				}
			} // end of for
		}
		cnt++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		for (int f = 0; f < m; f++) {
			arr[i][f] = str[f] - '0';
		}

	}
//	chk[0][0] = 1;
	cout << bfs();
}