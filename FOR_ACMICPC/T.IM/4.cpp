#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
vector<int>v[10001];
int cnt = 0;
void bfs(int cur) {
	queue<int>q;
	int chk[10001]{};
	q.push(cur);
	chk[cur] = 1;
	while (!q.empty()) {
		int frt = q.front(); q.pop();
		for (int i = 0; i < v[frt].size(); i++) {
			if (chk[v[frt][i]]) continue;
			chk[v[frt][i]] = 1;
			q.push(v[frt][i]);
			cnt++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	int k; // 출발지점
	int a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> k;
	bfs(k); cnt++;

	cout << n - cnt;
}