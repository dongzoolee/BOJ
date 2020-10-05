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
#include<set>
using namespace std;
using ll = long long;
#define MAX 5001
int d[MAX], finished[MAX], goDegree[MAX];
vector<int>vec[MAX];
vector<vector<int>>scc;
int par[MAX], chk[MAX];
int id;
stack<int>s;
priority_queue<int, vector<int>, greater<int>>q;
int dfs(int n) {
	d[n] = ++id;
	s.push(n);
	int parent = d[n];

	for (int i = 0; i < vec[n].size(); i++) {
		int y = vec[n][i];
		if (!d[y])
			parent = min(parent, dfs(y));
		else if (!finished[y])
			parent = min(parent, d[y]);
	}

	if (parent == d[n]) {
		vector<int>tmp;
		while (1) {
			int t = s.top();
			s.pop();
			tmp.push_back(t);
			finished[t] = 1;
			par[t] = scc.size();
			if (n == t) break;
		}
		scc.push_back(tmp);
	}
	//par[parent].push_back(n);
	return parent;
}
void init() {
	id = 0;
	memset(d, 0, sizeof(d));
	memset(finished, 0, sizeof(finished));
	memset(goDegree, 0, sizeof(goDegree));
	memset(par, 0, sizeof(par));
	memset(chk, 0, sizeof(chk));
	scc.clear();
	for (int i = 0; i < 5001; i++) {
		vec[i].clear();
		//par[i].clear();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int v, u;
	int a, b;
	while (1) {
		cin >> v;
		if (v == 0) break;
		cin >> u;
		while (u--) {
			cin >> a >> b;
			//goDegree[a]++;
			vec[a].push_back(b);
		}
		for (int i = 1; i <= v; i++)
			if (!d[i]) dfs(i);
		
		for (int i = 1; i <= v; i++)
			for (int f = 0; f < vec[i].size(); f++) {
				// SCC간의 연결관계 따질 때 중요함.
				if (par[i] != par[vec[i][f]])
					chk[par[i]] = 1;
			}

		for (int i = 0; i < scc.size(); i++)
			if (!chk[i])
				for (int f = 0; f < scc[i].size(); f++)
					q.push(scc[i][f]);

		while(!q.empty()) {
			cout << q.top() << ' ';
			q.pop();
		}
		cout << '\n';
		init();
	}
}