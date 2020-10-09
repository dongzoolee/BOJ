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
int n, m;
struct segtree {
	vector<ll>seg;
	ll base;
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		fill(seg.begin(), seg.end(), 0);
	}
	void update(ll a, ll b) {
		a += base - 1;
		ll cha = -seg[a] + b;
		for (ll i = a; i > 0; i /= 2)
			seg[i] += cha;
	}
	ll sum(ll l, ll r) {
		l += base - 1, r += base - 1;
		ll ret = 0;
		while (l <= r) {
			if (l % 2) {
				ret += seg[l++];
			}
			if (r % 2 == 0) {
				ret += seg[r--];
			}
			l /= 2, r /= 2;
		}
		return ret;
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	segtree st;
	cin >> n >> m;
	st.init();
	ll a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a) {
			st.update(b, c);
		}
		else {
			if (b > c) swap(b, c);
			cout << st.sum(b, c) << '\n';
		}
	}
}