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
vector<pair<int, pair<int, int>>>v[1001];
vector<pair<int, int>>save;
int chk[1001] = { 0 };
int n, m, k;
int s, t;
void dfs(int cur, int a, int b) {
	if (cur == t) {
		save.push_back({ a,b });
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
			int l = max(a, v[cur][i].second.first);
			int r = min(b, v[cur][i].second.second);
			if (l > r) continue;
			dfs(v[cur][i].first, l, r);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	cin >> s >> t;
	int a, b, c, d;
	while (m--) {
		cin >> a >> b >> c >> d;
		v[a].push_back({ b,{c,d} });
	}
	for (int i = 0; i < v[s].size(); i++) {
		dfs(v[s][i].first, v[s][i].second.first, v[s][i].second.second);
	}
	sort(save.begin(), save.end());
	int s = -1, ans=0;
	for (int i = 0; i < save.size(); i++) {
		if (s <= save[i].first) s = save[i].first;
		if (save[i].second < s) continue;
		ans += save[i].second - s + 1; s = save[i].second + 1;
	}
	cout << ans;
}