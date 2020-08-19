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
int mlen = 0, dia;
vector<pair<int, int>>v[10001];
int chk[10001];
void dfs(int idx, int len) {
	if (mlen < len) {
		mlen = len;
		dia = idx;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i].first]) continue;
		chk[v[idx][i].first] = 1;
		dfs(v[idx][i].first, len + v[idx][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	memset(chk, 0, sizeof(chk));
	dfs(dia, 0);
	cout << mlen;
}