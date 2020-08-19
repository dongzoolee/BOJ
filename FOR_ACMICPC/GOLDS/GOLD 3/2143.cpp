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
using namespace std;
using ll = long long;
ll ina[1000];
ll inb[1000];
vector<ll>a;
vector<ll>b;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	ll n;
	cin >> t >> n;
	for (ll i = 0; i < n; i++) {
		cin >> ina[i];
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> inb[i];
	}
	// 부분합 전부 push_back합니다.
	for (ll i = 0; i < n; i++) {
		ll sum = ina[i];
		a.push_back(sum);
		for (ll f = i + 1; f < n; f++) {
			sum += ina[f];
			a.push_back(sum);
		}
	}
	for (ll i = 0; i < m; i++) {
		ll sum = inb[i];
		b.push_back(sum);
		for (ll f = i + 1; f < m; f++) {
			sum += inb[f];
			b.push_back(sum);
		}
	}
	ll res = 0;
	sort(b.begin(), b.end());
	for (ll i = 0; i < a.size(); i++) {
		// lower_bound의 단점 & 그리고 보완점
		ll idx1 = lower_bound(b.begin(), b.end(), t - a[i]) - b.begin();
		ll idx2 = upper_bound(b.begin(), b.end(), t - a[i]) - b.begin();

		res += idx2 - idx1;
	}
	cout << res;
}