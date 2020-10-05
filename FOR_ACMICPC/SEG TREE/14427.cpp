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
ll n, m, base;
ll inp[MAX];
vector<pair<ll, ll>>tree;
void init() {
	// base 구하기
	for (base = 1; base < n; base *= 2);
	// base의 두 배로 tree size init
	tree.resize(2 * base);
	// input 넣기
	for (ll i = base; i < base + n; i++)
		tree[i] = { inp[i - base], i - base };
	for (ll i = base + n; i < base * 2; i++)
		tree[i] = { LLONG_MAX, -2 };
	// base-1부터 채우기
	for (ll i = base - 1; i > 0; i--) {
		if (tree[2 * i + 1].first < tree[2 * i].first)
			tree[i] = tree[2 * i + 1];
		else
			tree[i] = tree[2 * i];
	}
}
void update(ll a, ll b) {
	a += base-1;
	tree[a].first = b;
	for (ll i = a / 2; i; i /= 2) {
		if (tree[2 * i + 1].first < tree[2 * i].first)
			tree[i] = tree[2 * i + 1];
		else
			tree[i] = tree[2 * i];
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	ll a, b;
	for (ll i = 0; i < n; i++) {
		cin >> inp[i];
	}
	init();
	cin >> m;
	while (m--) {
		cin >> a;
		if (a == 1) {
			cin >> a >> b;
			update(a, b);
		}
		else {
			cout << tree[1].second + 1 << '\n';
		}
	}
}