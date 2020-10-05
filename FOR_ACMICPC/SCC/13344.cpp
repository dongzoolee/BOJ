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
#define MAX 50001
vector<pair<int, int>>v;
vector<int>vec[MAX];
vector<int>st;
vector<vector<int>>scc;
vector<pair<int, int>>big;
int par[MAX], d[MAX], done[MAX];
int id;
stack<int>s;
int dfs(int n) {
	d[n] = ++id;
	int parent = d[n];
	s.push(n);

	for (int i = 0; i < vec[n].size(); i++) {
		int y = vec[n][i];
		if (!d[y])
			parent = min(parent, dfs(y));
		else if (!done[y])
			parent = min(parent, d[y]);
	}

	if (parent == d[n]) {
		vector<int>tmp;
		while (1) {
			int t = s.top();
			s.pop();
			done[t] = 1;
			tmp.push_back(t);
			if (n == t) break;
		}
		scc.push_back(tmp);
	}
	return parent;
}
int find(int n) {
	if (n == par[n]) return n;

	return par[n] = find(par[n]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (a < b)swap(a, b);
	par[a] = b;
}
void init() {
	for (int i = 0; i < MAX; i++)
		par[i] = i;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	init();
	cin >> n >> m;
	int a, c;
	char b;
	while (m--) {
		cin >> a >> b >> c;
		if (b == '=') {
			if (a > c)swap(a, c);
			unite(a, c);
		}
		else {
			big.push_back({ a,c });
		}
	}
	for (int i = 0; i < big.size(); i++)
		if (par[big[i].first] == par[big[i].second]) {
			cout << "inconsistent";
			return 0;
		}
		else {
			// par[big[i].first] -> par[big[i].second]
			vec[par[big[i].first]].push_back(par[big[i].second]);
			st.push_back(par[big[i].first]);
			st.push_back(par[big[i].second]);
		}
	sort(st.begin(), st.end());
	st.erase(unique(st.begin(), st.end()), st.end());
	for (int i = 0; i < st.size(); i++)
		if (!d[st[i]]) dfs(st[i]);

	if (st.size() == scc.size()) {
		cout << "consistent";
	}
	else {
		cout << "inconsistent";
	}
}