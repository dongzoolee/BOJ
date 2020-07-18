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
int n, m, cnt = 1;
int mvx[] = { 1,0,-1,0 };
int mvy[] = { 0,-1,0,1 };
int dst[1000][1000][2] = { 1 };
//bool chk[1000][1000] = { 0 };
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
	//	bool chk[1000][1000] = { 0 };
	while (!q.empty()) {
		int fst = get<0>(q.front()), scd = get<1>(q.front()), wallcnt = get<2>(q.front()), dist = dst[fst][scd][wallcnt];
		q.pop();
		if (fst == n - 1 && scd == m - 1) { return dist; }
		for (int i = 0; i < 4; i++) {
			int y = fst + mvy[i], x = scd + mvx[i];
			if (arr[y][x] == 1 && wallcnt == 1) continue;

			if (y < 0 || y >= n || x < 0 || x >= m) continue;

			if (arr[y][x] == 1 && wallcnt == 0) {
				//chk[y][x] = 1; 이거 하면 어쩔건데;...............처음해보면서........
				// 사실 제일 빨리 접근한게 제일 합리적인 접근인줄알았다근데
				//아니더라................ 벽을 이미 부수고 해당 지점에 도달햇을 수도 잇고
				// 안 부수고 해당 지점에 도달하고 나중에 가서 벽을 부수는게 더 효율적일수도잇자나
				// 휴................................................................
				// 이건 걍 3차원 bfs인데 화나니까 tuple 4차원으로 갈게
				dst[y][x][1] = dist + 1;
				q.push({ y,x,1 });

				// 처음 구현은 visit 2차원 배열을 만들어 이미 지나간 곳은 방문하지 않도록 했다
				//	하지만 그렇게 구현한 코드는 예외케이스가 존재했다
				//	따라서 아래의 조건을 설정해야 했다
				//⭐️ 한 노드는 '벽을 부수고 온 경우' '벽을 부수지 않고 온 경우' 최대 2번 방문 가능하다
				// tistory - SuperM
			}
			// 왜 dst[y][x][wcnt]==0이 조건이고, 이걸로 시간을 줄여야하나?
			// dst[y][x][0]이 0이 아니면 bfs의 특성상, 이미 최단거리인 놈이 
			// 이 지점을 지나갔단 소리이므로 dst[y][x][0]이 !=0 이면 이 땐 최단거리가 아니다.
			// dst[y][x][1]도 마찬가지...
			if (arr[y][x] == 0 && dst[y][x][wallcnt] == 0) {
				//chk[y][x] = 1;
				dst[y][x][wallcnt] = dist + 1;
				q.push({ y,x,wallcnt });
			}
		}
	} // end of for
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
	cout << bfs();
}