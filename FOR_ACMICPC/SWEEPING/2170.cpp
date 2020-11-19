#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int n, m;
struct seg {
	vector<int>seg;
	int base;
	void init() {
		for (base = 1; base < n; base *= 2);
		seg.resize(base * 2);
		for (int i = base; i < base + n; i++)
			seg[i] = 1;
		seg[base + n] = 0;
		for (int i = base - 1; i > 0; i--)
			seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	void update(int l, int r) {
		l += base, r += base;
		
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	seg tree;
	tree.init();
	int a, b;
	while (m--) {
		cin >> a >> b;
		tree.update(a, b);
	}
}