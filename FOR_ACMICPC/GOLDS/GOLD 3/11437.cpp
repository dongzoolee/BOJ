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
#include<numeric>
using namespace std;
using ll = long long;
int n, m;
void dfs(int idx, int depth, vector<int>tree[10001], int chk[10001], int dep[10001], int par[][21]) {
	if (chk[idx]) return;

	chk[idx] = 1;
	dep[idx] = depth;
	for (int i = 0; i < tree[idx].size(); i++) {
		if (chk[tree[idx][i]]) continue;
		par[tree[idx][i]][0] = idx;
		dfs(tree[idx][i], depth + 1, tree, chk, dep, par);
	}
}
void parent(int par[][21]) {
	for (int f = 1; f < 21; f++)
		for (int i = 1; i <= n; i++)
			par[i][f] = par[par[i][f - 1]][f - 1];
}
int lca(int a, int b, int par[][21], int dep[10001]) {
	// 같은 depth로 맞춰주기
	if (dep[a] < dep[b]) //  무조건 a가 크게
		swap(a, b);
	for (int i = 20; i >= 0; i--) 	// 깊이 일치할 때까지 자신의 깊이를 낮춤
		if (dep[a] - dep[b] >= (1 << i)) {
			a = par[a][i];
		}

	if (a == b) return a;
	// find ancestor
	for (int i = 20; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			// 일치하지 않는 순간, 해당 부모를 자신으로 만들어서
			// 이동한 후의 2^0번째 부모를 출력한다.
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int>tree[10001];
		int par[10001][21] = { 0 }, dep[10001] = { 0 };
		int chk[10001] = { 0 };
		cin >> n;
		int a, b;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		// par & depth init
		dfs(1, 0, tree, chk, dep, par);
		// parentsss init
		parent(par);
		// to find
			cin >> a >> b;
			cout << lca(a, b, par, dep) << '\n';
	}
}