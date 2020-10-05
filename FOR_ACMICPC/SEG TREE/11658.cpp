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
int inp[1025][1025];
vector<int>tree[1025];
vector<vector<int>>seg;
int base, n, m;
void update(int a, int b, int c) {
	b += base - 1;
	int cha = -tree[a][b] + c;
	for (int i = b; i; i /= 2) {
		tree[a][i] += cha;
	}
}

int sum(int a, int b, int c, int d) {
	b += base - 1, d += base - 1;
	int l, r, ret = 0;
	for (int i = a; i <= c; i++) {
		l = b, r = d;
		while (l <= r) {
			if (l % 2)
				ret += tree[i][l++];
			if (r % 2 == 0)
				ret += tree[i][r--];
			l /= 2, r /= 2;
		}
	}
	return ret;
}
void init() {
	for (base = 1; base < n; base *= 2);
	for (int i = 1; i <= n; i++) {
		tree[i].resize(base * 2);
		for (int f = base; f < base + n; f++)
			tree[i][f] = inp[i][f - base + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int f = base - 1; f; f--) {
			tree[i][f] = tree[i][f * 2] + tree[i][f * 2 + 1];
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int f = 1; f <= n; f++)
			cin >> inp[i][f];
	init();
	int a, b, c, d, e;
	while (m--) {
		cin >> a;
		if (!a) {
			cin >> b >> c >> d;
			update(b, c, d);
		}
		else {
			cin >> b >> c >> d >> e;
			if (b >= d && c >= e) {
				swap(b, d);
				swap(c, e);
			}
			cout << sum(b, c, d, e) << '\n';
		}
	}
}
