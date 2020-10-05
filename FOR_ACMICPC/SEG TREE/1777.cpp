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
vector<int>tree;
vector<int>res;
int base, n;
int inp[100001];
void update(int idx, int cnt) {
	int st = 1;

	while (base > st) {
		if (tree[st * 2 + 1] <= cnt) {
			cnt -= tree[st * 2 + 1];
			tree[st * 2]--;
			st *= 2;
		}
		else {
			tree[st * 2+1]--;
			st = st * 2 + 1;
		}
	}
	res[st - base] = idx;
}
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	res.resize(base);
	for (int i = base; i < base + n; i++)
		tree[i] = 1;
	for (int i = base - 1; i; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a;
	init();
	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	for (int i = n - 1; i >= 0; i--)
		update(i + 1, inp[i]);
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
}