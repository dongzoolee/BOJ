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
int inp[100001];
int n, m;
int base;
int max_, min_;
vector<pair<int, int>>tree;
void find(int l, int r) {
	l += base - 1, r += base - 1;
	max_ = INT_MIN;
	min_ = INT_MAX;

	while (l <= r) {
		if (max_ < tree[l].first) {
			max_ = tree[l].first;
		}
		if (min_ > tree[l].second) {
			min_ = tree[l].second;
		}
		l++;

		if (max_ < tree[r].first) {
			max_ = tree[r].first;
		}
		if (min_ > tree[r].second) {
			min_ = tree[r].second;
		}
		r--;
		l /= 2, r /= 2;
	}
	return;
}
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	for (int i = base; i < base + n; i++)
		tree[i] = { inp[i - base],inp[i - base] };
	for (int i = base + n; i < base * 2; i++)
		tree[i] = { INT_MAX, INT_MIN };

	for (int i = base - 1; i > 0; i--)
		tree[i] = { max(tree[i * 2].first, tree[i * 2 + 1].first),min(tree[i * 2].second, tree[i * 2 + 1].second) };
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	init();

	int a, b;
	while (m--) {
		cin >> a >> b;
		find(a, b);
		cout << min_ << ' ' << max_ << '\n';
	}
}