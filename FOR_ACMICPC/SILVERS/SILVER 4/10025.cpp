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
//				   ICE, LOC
ll n, k;
//ll field[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	v.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		//field[v[i].second] = v[i].first;
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return b.second > a.second; });
	ll sum = 0;
	ll l = 0, r=0;
	// 양팔쭉
	for (int i = 0;v.size()>i && v[0].second + 2 * k >= v[i].second; i++) {
		sum += v[i].first;
		r = i;
	}
	ll max_ = sum;
	ll cur = v[0].second + k;
	ll end = v[v.size() - 1].second - k;
	for (int i = cur; i <= end; i++) {
		if (v[l].second < i - k) sum -= v[l++].first;
		if (r + 1 < v.size() && v[r + 1].second <= i + k) sum += v[++r].first;
		max_ = max(max_, sum);
	}
	cout << max_;
}