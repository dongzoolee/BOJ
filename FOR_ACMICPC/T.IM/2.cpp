#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
vector<int>v[10001];
bool chk[10001] = { 0 };
vector<int>able;
bool ans[10001] = { 0 };
int cnt = 0, k; // 출발지점
void adding() {
	for (int i = 0; i < able.size(); i++)
		ans[able[i]] = 1;
}
void dfs(int idx) {
	if (idx == k) { adding();  return; } // 도달가능 1 처리
	for (int i = 0; i < v[idx].size(); i++) {
		if (ans[v[idx][i]]) return adding();
		if (chk[v[idx][i]]) continue;
		able.push_back(v[idx][i]);
		chk[v[idx][i]] = 1;
		dfs(v[idx][i]);
		able.pop_back();
		chk[v[idx][i]] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	int a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		able.push_back(i); // 도달가능 정점 담는 용도
		chk[i] = 1;
		dfs(i);
		chk[i] = 0;
		able.pop_back();
	}
	if (ans[k])
		cout << n - accumulate(ans + 1, ans + n + 1, 0);
	else
		cout << n - accumulate(ans + 1, ans + n + 1, 0) - 1;
}