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
#define MX 10001
vector<int>vec[MX];
vector<vector<int>>scc;
stack<int>s;
int d[MX], done[MX];
int id;
int dfs(int n) {
	d[n] = ++id;
	int parent = d[n];
	s.push(n);

	for (int i = 0; i < vec[n].size(); i++) {
		int y = vec[n][i];
		// 방문 전
		if (!d[y])
			parent = min(parent, dfs(y));
		// 방문 but 아직 진행중
		else if (!done[y])
			parent = min(parent, d[y]);
	}

	if (parent == d[n]) { // 자기에게 돌아왔을 때
		vector<int>tmp;
		while (1) {
			int t = s.top();
			s.pop();
			tmp.push_back(t);
			done[t] = 1;
			if (t == n) break;
		}
		scc.push_back(tmp);
	}

	return parent;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e;
	cin >> v >> e;
	int a, b;
	while (e--) {
		cin >> a >> b;
		vec[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if (!d[i])
			dfs(i);
	}
	for (int i = 0; i < scc.size(); i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());

	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); i++) {
		for (int f = 0; f < scc[i].size(); f++)
			cout << scc[i][f] << ' ';
		cout << -1 << '\n';
	}
}
