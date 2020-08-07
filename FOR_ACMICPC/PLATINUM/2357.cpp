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
ll inp[100'001];
// 왜 +1해주나요
vector<pair<ll, ll>>tree;
ll n, m, base;

void find(ll l, ll r) {
	ll min_ = LLONG_MAX, max_ = 0;
	//범위 재조정
	l += base, r += base;
	while (l <= r) {
		//if 두 개
		if (l % 2) { if(tree[l].first) min_ = min(tree[l].first, min_); if (tree[l].second) max_ = max(tree[l++].second, max_); }
		if (r % 2 == 0) { if (tree[r].first) min_ = min(tree[r].first, min_); if (tree[r].second) max_ = max(tree[r--].second, max_); }
		//트리 올라가기
		l /= 2, r /= 2;
	}
	cout << min_ << ' ' << max_ << '\n';
}

void init() {
	// base 구하기
	for (base = 1; base < n; base *= 2);
	// input의 두 배
	tree.resize(base * 2 + 1);
	// inp정리
	for (int i = 0; i < n; i++)
		tree[i + base].first = tree[i+base].second = inp[i];
	// base - 1부터 채우는 이유
	for (int i = base - 1; i > 0; i--) {
		tree[i].first = min(tree[2 * i].first, tree[2 * i + 1].first);
		tree[i].second = max(tree[2 * i].second, tree[2 * i + 1].second);
	}
}
//void update_min(ll i, ll v) {
//	// i번째 노드를 v로 변경
//	ll dif = -trmin[i + base] + v;
//	for (i += base; i; i /= 2) trmin[i] += dif;
//}
//void update_max(ll i, ll v) {
//	// i번째 노드를 v로 변경
//	ll dif = -trmax[i + base] + v;
//	for (i += base; i; i /= 2) trmax[i] += dif;
//}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++)
		cin >> inp[i];
	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		find(a, b);
	}
}