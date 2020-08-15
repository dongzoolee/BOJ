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
vector<int>v[100001];
int par[100001];
int chk[100001];
void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (chk[v[idx][i]]) continue;
		chk[v[idx][i]] = 1;
		par[v[idx][i]] = idx;
		dfs(v[idx][i]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	chk[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << par[i] << '\n';
}
