#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
using ll = long long;
int n, m;
vector<int>v[10001];
int visited[10001];
int cnt[100001];
int chk[10001];
vector<int>root;
void dfs(int idx, int root, int visited[10001]) {
	if (!v[idx].size()) { return; }

	for (int i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i]]) continue;

		cnt[root]++;
		visited[v[idx][i]] = 1;
		dfs(v[idx][i], root, visited);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[b].push_back(a);
		chk[a] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (chk[i] == 0)
			root.push_back(i);
	// 목적지를 루트로 잡음
	// 면 안돼 !!!!!!!!!!!!!!!!!!!!!!!!!!
	// 사이클이 있을 수 있잖아...
	for (int i = 1; i <= n; i++) {
		int visited[10001]{};
		cnt[i] = 1;
		visited[i] = 1;
		dfs(i, i, visited);
	}
	int mx = *max_element(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++)
		if (cnt[i] == mx)
			cout << i << ' ';
}