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
int par[201];
void init() {
	// 1. √ ±‚»≠
	for (int i = 0; i <= 200; i++)
		par[i] = i;
}
int find(int u) {
	if (par[u] == u) return u;

	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);

	if (u == v) return;
	par[u] = v;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	init();
	int a[201];
	for (int i = 1; i <= n; i++)
		for (int f = 1; f <= n; f++) {
			cin >> a[f];
			if (a[f] == 1)
				merge(i, f);
		}
	int arr[1000];
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	for (int i = 1; i < m; i++) {
		if (find(arr[i - 1]) != find(arr[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}