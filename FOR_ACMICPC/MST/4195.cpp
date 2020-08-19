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
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int par[100001];
int cnt[100001];
void init() {
	for (int i = 0; i < 100001; i++)
		par[i] = i;
}
int find(int a) {
	if (par[a] == a) return a;

	return par[a] = find(par[a]);
}
void unite(int u, int v) {
	if (u == v) return;
	par[v] = u;
	// ESSENTIAL //
	cnt[u] += cnt[v];
	cnt[u]++;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int n;
	string st1, st2;
	while (tc--) {
		init();
		vector<pair<string, string>>order;
		vector<string>name;
		cin >> n;
		while (n--) {
			cin >> st1 >> st2;
			order.push_back({ st1,st2 });
			name.push_back(st1);
			name.push_back(st2);
		}
		sort(name.begin(), name.end());
		name.erase(unique(name.begin(), name.end()), name.end());
		for (int i = 0; i < order.size(); i++) {
			int l = lower_bound(name.begin(), name.end(), order[i].first) - name.begin();
			int r  = lower_bound(name.begin(), name.end(), order[i].second) - name.begin();
			l = find(l), r = find(r);
			if (l > r) swap(l, r);
			unite(l,r);
			cout << cnt[l] + 1 << '\n';
		}
		memset(cnt, 0, sizeof(cnt));
	}
}