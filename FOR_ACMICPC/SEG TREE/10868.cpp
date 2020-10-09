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
	vector<int>seg;
	int base;
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		for (int i = base; i < base + n; i++)
			cin >> seg[i];
		for (int i = base + n; i < base * 2; i++)
			seg[i] = 2'000'000'000;
		for (int i = base - 1; i > 0; i--)
			seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
	int get_min(int l, int r) {
		l += base - 1, r += base - 1;
		int min_ = INT_MAX;
		while (l <= r) {
			if (l % 2) {
				min_ = min(min_, seg[l++]);
			}
			if (r % 2 == 0) {
				min_ = min(min_, seg[r--]);
			}
			l /= 2, r /= 2;
		}
		return min_;
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	segtree st;
	cin >> n >> m;
	st.init();
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << st.get_min(a, b) << '\n';
	}
}