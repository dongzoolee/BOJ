#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
#include <limits.h>
using namespace std;
using ll = long long;
vector<ll>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, k, a;
	cin >> n >> k;
	ll tmp = n;
	ll min_ = LLONG_MAX, max_ = 0;
	while (tmp--) {
		cin >> a;
		v.push_back(a);
		min_ = min(min_, a);
		max_ = max(max_, a);
	}
	ll res;
	ll start = min_;
	ll end = max_ + k;
	ll mid = (start + end) / 2;
	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;
		for (ll i = 0; i < v.size(); i++)
			if (mid > v[i])
				sum += mid - v[i];

		if (sum <= k) {
			res = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << res;
}