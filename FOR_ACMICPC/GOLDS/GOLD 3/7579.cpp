#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
vector<pair<ll, ll>>v;
ll dp[101][10001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	v.resize(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) cin >> v[i].first;
	for (ll i = 0; i < n; i++) { cin >> v[i].second; sum += v[i].second; }
	sort(v.begin(), v.end());
	ll res = LLONG_MAX;
	// init
	for (ll f = v[0].second; f <= sum; f++)
		dp[0][f] = v[0].first;
	for (ll i = 1; i < n; i++)
		for (ll f = 0; f <= sum; f++) {
			if (f < v[i].second)
				dp[i][f] = dp[i - 1][f];
			else
				dp[i][f] = max(dp[i - 1][f - v[i].second] + v[i].first, dp[i - 1][f]);
			if (dp[i][f] >= m)
				res = min(res, f);
		}
	cout << res;
}