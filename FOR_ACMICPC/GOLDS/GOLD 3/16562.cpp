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
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
vector<int> par;
vector<int>cnt(10001, 1);
vector<int> v;
vector<pair<int,int>> arr;
int n, m, k;
bool chk[10001] = { 0 };

void init() {
	for (int i = 1; i <= n; i++)
		par[i] = i;
}
int find(int u) {
	if (par[u] == u) return par[u];

	return par[u] = find(par[u]);
}
void unite(int a,int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	// 생각해서 부모배정하기 !!
	if (a > b) swap(a, b);
	par[b] = a;
	cnt[a] += cnt[b];
	cnt[b] = 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> n >> m >> k;
	par.resize(n + 1);
	init();
	for (int i = 1; i <= n; i++) { cin >> a; arr.push_back({ a,i }); }
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unite(a, b);
	}
	// 비용 작은 순으로 친구받기
	sort(arr.begin(), arr.end());
	int sum = 0;
	int stud = 0;
	for (int i = 0; i < n; i++) {
		int prnt = find(arr[i].second);
		if (chk[prnt]) continue;
		chk[prnt] = 1;
		sum += arr[i].first;
		stud += cnt[prnt];
		if (sum > k) break;
		if (stud == n) { cout << sum; exit(0); }
	}
	cout << "Oh no";
}