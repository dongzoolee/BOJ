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
#define MAX 100001
vector<int>v[MAX];
vector<vector<int>>scc;
int d[MAX], done[MAX], myNum[MAX], inDegree[MAX];
int id;
stack<int>s;
int dfs(int n) {
	d[n] = ++id;
	int parent = d[n];
	s.push(n);

	for (int i = 0; i < v[n].size(); i++) {
		int y = v[n][i];

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
			myNum[t] = scc.size();
			tmp.push_back(t);

			if (n == t) break;
		}
		scc.push_back(tmp);
	}
	return parent;
}
void init() {
	for (int i = 0; i < MAX; i++)
		v[i].clear();
	scc.clear();
	memset(d, 0, sizeof(d));
	memset(done, 0, sizeof(done));
	memset(myNum, 0, sizeof(myNum));
	memset(inDegree, 0, sizeof(inDegree));
	id = 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int n, m;
	int a, b;
	while (tc--) {
		cin >> n >> m;
		while (m--) {
			cin >> a >> b;
			v[a].push_back(b);
		}
		for (int i = 0; i < n; i++)
			if (!d[i])
				dfs(i);


		for (int i = 0; i < n; i++)
			for (int f = 0; f < v[i].size(); f++) {
				if (myNum[i] != myNum[v[i][f]])
					inDegree[myNum[v[i][f]]]++;
			}

		int cnt = 0;
		for (int i = 0; i < scc.size(); i++)
			if (!inDegree[i])
				cnt++;

		if (cnt == 1) {
			for (int i = 0; i < scc.size(); i++)
				if (!inDegree[i]) {
					sort(scc[i].begin(), scc[i].end());
					for (int f = 0; f < scc[i].size(); f++)
						cout << scc[i][f] << '\n';
				}
			cout << '\n';
		}
		else {
			cout << "Confused\n\n";
		}
		init();
	}
}
