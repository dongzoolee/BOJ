#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using ll = long long;
int  n, m, sum = 0;
vector<pair<int,pair<int, int>>>v;
int par[1001];

void init() {
	for (int i = 1; i < 1001; i++)
		par[i] = i;
}

int find(int u) {
	if (par[u] == u)
		return u;

	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);

	if (u == v) return;

	par[u] = v;
}

void judge() {
	for (int i = 0; i < m; i++) {
		if (find(v[i].second.first) != find(v[i].second.second)) {
			merge(v[i].second.first, v[i].second.second);
			sum += v[i].first;
		}

	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a,b,c;
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	judge();
	cout << sum;
}