#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int n, m, cnt = 0;
vector<int>v[101];
bool chk[101];
void bfs() {
	queue<int>q;
	q.push(1);
	chk[1] = 1;
	while (!q.empty()) {
		int frt = q.front(); q.pop();
		for (int i = 0; i < v[frt].size(); i++) {
			if (chk[v[frt][i]]) continue;
			q.push(v[frt][i]);
			chk[v[frt][i]] = 1;
			cnt++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	cout << cnt;
}