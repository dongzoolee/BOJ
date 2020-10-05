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
int n, m, k;

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
			// base 이상의 범위는 제거!
			if (node < base) {
				// ****seg가 아니라 lazy에 넣어줘야댐
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			seg[node] += lazy[node] * (ne - ns);
			lazy[node] = 0;
		}
	}
	//////////////////////////////////////////////// 1부터 시작 ////////
	void add(int l, int r, ll k) { return add(l, r, k, 1, 0, base); }
	void add(int l, int r, ll k, int node, int ns, int ne) {
		// 일단 propagate로 시작
		propagate(node, ns, ne);

		// 구간 제거
		if (r <= ns || ne <= l) return;
		if (l <= ns && ne <= r) {
			// node가 ns와 ne에 완전 포함되는 거니까
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		add(l, r, k, node * 2, ns, mid);
		add(l, r, k, node * 2 + 1, mid, ne);
		// 마지막에 자식들의 값을 사용하여 
		// 다시 자신의 값을 갱신
		// 이라고 하긴 하는데 밑의 문장이 꼭 필요한가????????
		// 없어도 될 듯 한데............
		// 지우니까 WA 받음 왜지
		// 
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}

	ll get(int l, int r) { return get(l, r, 1, 0, base); }
	ll get(int l, int r, int node, int ns, int ne) {
		// 시작은 항상 propagate
		propagate(node, ns, ne);

		// 구간 제거
		if (r <= ns || ne <= l) return 0;
		if (l <= ns && ne <= r) return seg[node];
		int mid = (ns + ne) / 2;
		return get(l, r, node * 2, ns, mid) + get(l, r, node * 2 + 1, mid, ne);
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	seg st;
	cin >> n >> m >> k;
	st.init();
	int t = m + k, a, b, c, d;
	while (t--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			st.add(b-1, c, d);
		}
		else {
			cin >> b >> c;
			cout << st.get(b-1, c) << '\n';
		}
	}
}