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
int n;
struct seg {
	vector<ll>seg;
	vector<ll>lazy;
	int base;
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		lazy.resize(base * 2);
		fill(lazy.begin(), lazy.end(), 0);
		for (int i = base; i < base + n; i++)
			cin >> seg[i];
		for (int i = base - 1; i > 0; i--)
			seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	void propagate(int node, int ns, int ne) {
		if (lazy[node]) {
			if (node < base) {
				// 기존 lazy가 있을 수 있기 때문에
				// = 이 아니라 +=이다.
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			seg[node] += lazy[node] * (ne - ns);
			lazy[node] = 0;
		}
	}
	void add(int l, int r, ll k) { add(l, r, k, 1, 0, base); }
	void add(int l, int r, ll k, int node, int ns, int ne) {
		propagate(node, ns, ne);
		if (r <= ns || ne <= l) return;
		if (l <= ns && ne <= r) {
			lazy[node] += k;
			propagate(node, ns, ne);
			// 더 이상 뭐 할게 없다 //
			// 그러니까 return //
			return;
		}
		int mid = (ns + ne) / 2;
		add(l, r, k, node * 2, ns, mid);
		add(l, r, k, node * 2 + 1, mid, ne);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
		//propagate(node, ns, ne);
	}
	ll get(int l, int r) { return get(l, r, 1, 0, base); }
	ll get(int l, int r, int node, int ns, int ne) {
		propagate(node, ns, ne);
		if (r <= ns || ne <= l) return 0;
		if (l <= ns && ne <= r) return seg[node];
		int mid = (ns + ne) / 2;

		return get(l, r, node * 2, ns, mid) + get(l, r, node * 2 + 1, mid, ne);
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	seg st;
	cin >> n;
	st.init();
	int m, a, b, c, d;
	cin >> m;
	while (m--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			st.add(b - 1, c, d);
		}
		else {
			cin >> b;
			cout << st.get(b-1, b) << '\n';
		}
	}
}