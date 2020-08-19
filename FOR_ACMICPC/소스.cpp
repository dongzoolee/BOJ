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
ll n;
vector<pair<ll, ll>>v[100001];
vector<ll>can;
vector<ll>yyy;
ll visited[100001];
ll ans = 0, endidx;
void dfs2(ll idx, ll len) {
	if (ans == len) {
		yyy.push_back(idx);
	}

	for (ll i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i].first]) continue;
		visited[idx] = 1;
		dfs2(v[idx][i].first, len + v[idx][i].second);
	}
}
void dfs1(ll idx, ll len) {
	if (ans < len) {
		ans = len;
		endidx = idx;
		can.push_back(ans);
	}

	for (ll i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i].first]) continue;
		visited[idx] = 1;
		dfs1(v[idx][i].first, len + v[idx][i].second);
	}
}
void dfs(ll idx, ll len) {
	if (ans < len) {
		ans = len;
		endidx = idx;
	}

	for (ll i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i].first]) continue;
		visited[idx] = 1;
		dfs(v[idx][i].first, len + v[idx][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	ll parent, child, length;
	for (ll i = 0; i < n - 1; i++) {
		cin >> parent >> child >> length;
		v[parent].push_back({ child, length });
		v[child].push_back({ parent, length });
	}

	//가장 멀리 있는 정점 구하기
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs2(1, 0);
	memset(visited, 0, sizeof(visited));
	for (ll i = 0; i < yyy.size(); i++) {
		memset(visited, 0, sizeof(visited));
		ans = 0;
		dfs1(yyy[i], 0);
	}
	sort(can.begin(), can.end());
	cout << can[can.size() - 2];
 }