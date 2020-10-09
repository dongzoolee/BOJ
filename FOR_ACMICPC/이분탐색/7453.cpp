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
vector<int>v1;
vector<int>v2;
int a[4000], b[4000], c[4000], d[4000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++)
			v1.push_back(a[i] + b[f]);
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++)
			v2.push_back(c[i] + d[f]);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll ans = 0;
	int sz = v1.size();
	int end = v2.size(), tmp;
	for (int i = 0; i < sz; i++) {
		tmp = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		if (tmp != end)
			ans += (upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin()) - tmp;
	}
	cout << ans;
}