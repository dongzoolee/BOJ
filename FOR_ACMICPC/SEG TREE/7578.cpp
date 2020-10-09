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
vector<pair<int, int>>v;
vector<pair<int, int>>order;
int n;
struct segtree {
	vector<int>seg;
	int base;
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		for (int i = base; i < base + n; i++)
			seg[i] = 1;
		for (int i = base + n; i < base * 2; i++)
			seg[i] = 0;
		for (int i = base - 1; i > 0; i--)
			seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	void update(int a) {
		a += base - 1;
		for (int i = a; i > 0; i /= 2)
			seg[i]--;
	}
	int sum(int l, int r) {
		int ret = 0;
		r += base - 1;
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
	int a;
	cin >> n;
	segtree st;
	st.init();

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cin >> a;
		order.push_back({ v[lower_bound(v.begin(), v.end(), make_pair(a, 0)) - v.begin()].second + 1, i + 1 });
	}
	sort(order.begin(), order.end(), greater<>());
	ll ans = 0;
	for (int i = 0; i < order.size(); i++) {
		st.update(order[i].second);
		ans += (order[i].second - 1) - st.sum(st.base, order[i].second);
	}
	cout << ans;
}