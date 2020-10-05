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
ll inp[100001];
ll n, q, base;
vector<ll>tree;
ll find(ll l, ll r) {
	l += base - 1, r += base - 1;
	ll ret = 0;
	while (l <= r) {
		if (l % 2)
			ret += tree[l++];
		if (r % 2 == 0)
			ret += tree[r--];
		l /= 2, r /= 2;
	}
	return ret;
}
void update(ll a, ll b) {
	a += base - 1;
	ll gap = -tree[a] + b;
	tree[a] += gap;
	for (ll i = a / 2; i; i /= 2) {
		tree[i] += gap;
	}
}
void init() {
	for (base = 1; base < n; base *= 2) ;
	tree.resize(base * 2);
	for (ll i = base; i < base + n; i++)
		tree[i] = inp[i - base];

	for (ll i = base - 1; i; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)
		cin >> inp[i];
	init();
	ll a, b, c, d;
	while (q--) {
		cin >> a >> b >> c >> d;
		if (a > b) swap(a, b);
		cout << find(a, b) << '\n';
		update(c, d);
	}
}