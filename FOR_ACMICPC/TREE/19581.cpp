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
int mlen = 0, dia, sec, fst;
vector<pair<int, int>>v[100001];
bool chk[100001];
void dfs2(int idx, int len) {
	if (mlen < len && idx != fst) {
		mlen = len;
		dia = idx;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i].first]) continue;
		chk[v[idx][i].first] = 1;
		dfs2(v[idx][i].first, len + v[idx][i].second);
	}
}
void dfs1(int idx, int len) {
	if (mlen < len && idx != sec) {
		mlen = len;
		dia = idx;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i].first]) continue;
		chk[v[idx][i].first] = 1;
		dfs1(v[idx][i].first, len + v[idx][i].second);
	}
}
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
	dfs(1, 0); // 임의의 점에서 제일 먼 곳을 찾습니다.

	memset(chk, 0, sizeof(chk));
	fst = dia;
	mlen = 0;
	chk[dia] = 1;
	dfs(dia, 0); // 지름의 한 점으로부터 다른 지름을 찾습니다.
	sec = dia;
	int ans = 0;

	memset(chk, 0, sizeof(chk));
	mlen = 0;
	chk[fst] = 1;
	dfs1(fst, 0); // 한 쪽 지름으로부터 (다른 쪽 지름을 제외한) 제일 먼 점을 찾습니다.
	ans = max(ans, mlen);

	memset(chk, 0, sizeof(chk));
	mlen = 0;
	chk[sec] = 1;
	dfs2(sec, 0); // 한 쪽 지름으로부터 (다른 쪽 지름을 제외한) 제일 먼 점을 찾습니다.
	ans = max(ans, mlen);
	cout << ans;
}