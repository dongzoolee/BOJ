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
#define MAX 100001
vector<pair<int, int>>tree;
int n, m, base;
int inp[MAX];

int find(int l, int r) {
	int min_ = INT_MAX;
	int idx = INT_MAX;
	l += base - 1, r += base - 1;
	while (l <= r) {
		if (l % 2) {
			if (tree[l].first < min_) {
				min_ = tree[l].first;
				idx = tree[l].second;
				// ¾Æ..........................................................
				// .............................................................
				// if (idx > tree[l].second)
				// 	idx = tree[l].second;
			}
			else if (tree[l].first == min_ && idx > tree[l].second)
				idx = tree[l].second;
			l++;
		}
		if (r % 2 == 0) {
			if (tree[r].first < min_) {
				min_ = tree[r].first;
				idx = tree[r].second;
				// ¾Æ..........................................................
				// .............................................................
				// if (idx > tree[l].second)
				// 	idx = tree[l].second;
			}
			else if (tree[r].first == min_ && idx > tree[r].second)
				idx = tree[r].second;
			r--;
		}
		l /= 2, r /= 2;
	}
	return idx;
}
void update(int a, int b) {
	a += base - 1;
	tree[a].first = b;
	for (int i = a / 2; i; i /= 2) {
		if (tree[i * 2 + 1].first < tree[i * 2].first)
			tree[i] = tree[i * 2 + 1];
		else
			tree[i] = tree[i * 2];
	}
}
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	for (int i = base; i < base + n; i++)
		tree[i] = { inp[i - base], i - base + 1 };
	for (int i = base + n; i < base * 2; i++)
		tree[i] = { INT_MAX,-1 };

	for (int i = base - 1; i > 0; i--) {
		if (tree[i * 2 + 1].first < tree[i * 2].first)
			tree[i] = tree[i * 2 + 1];
		else
			tree[i] = tree[i * 2];
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inp[i];
	init();

	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a;
		cin >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << find(b, c) << '\n';
		}
	}
}