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
int base,n;
vector<int>tree;
vector<int>ans;
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	ans.resize(base);
	for (int i = base; i < base + n; i++)
		tree[i] = 1;
	for (int i = base - 1; i; i--)
		tree[i] = tree[2 * i] + tree[2 * i + 1];
}
void update(int idx, int cnt) {
	int st = 1;
	while (st < base) {
		if (tree[2 * st] <= cnt) {
			cnt -= tree[2 * st];
			st = 2 * st + 1;
			tree[st]--;
		}
		else {
			st = 2 * st;
			tree[st]--;
		}
	}
	ans[st - base] = idx;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	init();
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		update(i, a);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] + 1<< '\n';
}