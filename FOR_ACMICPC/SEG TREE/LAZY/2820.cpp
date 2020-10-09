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
vector<pair<int, int>>v[500001];
struct seg {
	vector<int>seg;
	vector<int>lazy;
	int base;
	void init() {
		lazy.resize(n + 1);
		fill(lazy.begin(), lazy.end(), 0);
	}
	void propagate(int node, int ns, int ne) {
		if (lazy[node]) {
			if (node < base) {
				for (int i = 0; i < v[node].size(); i++)
					lazy[v[node][i].first]] += lazy[node];
			}
			seg[node] += v[node].size() * lazy[node];
			lazy[node] = 0;
		}
	}
	void add(int l, int r, int k) { add(l, r, k, 1, 0, base); }
	void add(int l, int r, int k, int node, int ns, int ne) {
		propagate(node, ns, ne);
		if (r <= ns || ne <= l) return;
		if (l <= ns && ne <= r) {
			// 꼭 !!!!! +=으로 해주자 // x
			// 남아있는 lazy가 있을 수 있으니까 //
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		add(l, r, k, node * 2, ns, mid);
		add(l, r, k, node * 2 + 1, mid, ne);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	seg st;
	cin >> n >> m >> k;
	int a, b;
	st.init();
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		v[i].push_back({ a,b });
	}
	while (m--) {
	}
}