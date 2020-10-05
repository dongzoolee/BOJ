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
int inp[500001];
int n, base, dep;
int tp[20];
vector<int>tree;
vector<pair<int,int>>stu;
vector<int>ans;
void update(int idx) {
	int ret = 0;
	idx += base;
	int tmp = idx;
	while (idx) {
		tree[idx] += 1;
		if (idx % 2) {
			ret += tree[idx - 1];
		}
		idx /= 2;
	}
	ans[tmp -base] = ret;
}
void init() {
	for (base = 1; base < n; base *= 2);
	tree.resize(base * 2);
	ans.resize(base);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	init();
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		stu.push_back({ a,i });
	}
	sort(stu.begin(), stu.end(), greater<>());
	for (int i = 0; i < n; i++)
		update(stu[i].second);

	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << '\n';
}