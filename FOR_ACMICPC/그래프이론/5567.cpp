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
int par[501];
vector<int>v[501];
int depth = 0, cnt = 0;
void bfs() {
	int chk[501]{};
	queue<int>q;
	chk[1] = 1;
	q.push(1);
	while (!q.empty()) {
		if (depth == 2) return;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			for (int f = 0; f < v[q.front()].size(); f++) {
				if (chk[v[q.front()][f]]) continue;
				q.push(v[q.front()][f]);
				chk[v[q.front()][f]] = 1;
				cnt++;
			}
			q.pop();
		}
		depth++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	cout << cnt;
}
