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
#define MAX 1000000
ll inp[MAX];
ll n, m, k;
ll base;
vector<ll>tree;
ll find(ll l, ll r) {
	l += base - 1, r += base - 1;
	ll ret = 1;
	while (l <= r) {
		if (l % 2) {
			ret = ret * tree[l] % 1'000'000'007;
			l++;
		}
		if (r % 2 == 0) {
			ret = ret * tree[r] % 1'000'000'007;
			r--;
		}
		l /= 2, r /= 2;
	}
	return ret;
}
void update(ll a, ll b) {
	a += base - 1;
	tree[a] = b;
	for (ll i = a / 2; i; i /= 2) {
		tree[i] = tree[2 * i] * tree[2 * i + 1] % 1'000'000'007;
	}
}
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	for (ll i = base; i < base + n; i++)
		tree[i] = inp[i - base];
	for (ll i = base + n; i < base * 2; i++)
		tree[i] = 1;// ?

	for (ll i = base - 1; i > 0; i--)
		tree[i] = tree[2 * i] * tree[2 * i + 1] % 1'000'000'007;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++)
		cin >> inp[i];
	init();
	ll cnt = m + k,a,b,c;
	while (cnt--) {
		cin >> a>>b>>c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << find(b, c)<<'\n';
		}
	}
}