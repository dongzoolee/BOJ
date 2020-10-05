#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
vector<int>v[1001];
int n, k;
int inDegree[1001], time[1001], ans[1001];
void topo() {
	queue<pair<int, int>>q;

	// 1. queue init
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push({ i, time[i] });
			// 아무 노드에도 연결 안되어있는
			// 노드의 승리가능성..
			ans[i] = time[i];
		}
	}


	while (!q.empty()) {
		int frt = q.front().first;
		int frtTime = q.front().second;
		q.pop();

		for (int i = 0; i < v[frt].size(); i++) {
			int y = v[frt][i];

			ans[y] = max(ans[y], frtTime + time[y]);
				if (--inDegree[y] == 0) {
					q.push({ y, ans[y] });
				}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int a, b;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> time[i];
		while (k--) {
			cin >> a >> b;
			v[a].push_back(b);
			inDegree[b]++;
		}
		topo();
		int w; cin >> w;
		cout << ans[w] << '\n';
		memset(inDegree, 0, sizeof(inDegree));
		memset(time, 0, sizeof(time));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 1001; i++)
			v[i].clear();
	}
}
