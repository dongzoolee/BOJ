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
vector<int>v[401];
vector<int>rev[401];
int par[401];
int chk[401];
int a, b, rit=0, revse = 0;
void rfs(int idx) {
	if (idx == b) { revse = 1; return; }

	for (int i = 0; i < rev[idx].size(); i++) {
		if (chk[rev[idx][i]]) continue;
		chk[rev[idx][i]] = 1;
		rfs(rev[idx][i]);
	}

}
void dfs(int idx) {
	if (idx == b) { rit = 1; return; }

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i]]) continue;
		chk[v[idx][i]] = 1;
		dfs(v[idx][i]);
	}

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	int n, k;
	cin >> n >> k;
	while (k--) {
		cin >> a >> b;
		v[a].push_back(b);
		rev[b].push_back(a);
		par[b] = a;
	}
	int s;
	cin >> s;
	while (s--) {
		memset(chk, 0, sizeof(chk));
		rit = revse = 0;

		cin >> a >> b;
		dfs(a);
		if (rit) {
			cout << -1<<'\n';
			continue;
		}
		memset(chk, 0, sizeof(chk));
		rfs(a);
		if (revse) {
			cout << 1<<'\n';
			continue;
		}
		cout << 0 << '\n';
	}

}