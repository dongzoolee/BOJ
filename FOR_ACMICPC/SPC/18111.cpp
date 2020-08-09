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
	vector<pair<ll,ll>>v[501];
	int main() {
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		ll n, m, b;
		ll min_ = LLONG_MAX, max_ = 0;
		cin >> n >> m >> b;
		ll a;
		for (ll i = 0; i < n; i++)
			for (ll f = 0; f < m; f++) {
				cin >> a;
				v[a].push_back({ i,f });
				min_ = min(a, min_);
				max_ = max(a, max_);
			}
		ll time = 0;
		while (min_ != max_) {
			ll cnt = 0;
			ll cnt2 = 0;
			cnt += v[min_].size();
			cnt2 += v[max_].size();

			if (min_ == 256) {
				for (ll i = 0; i < v[max_].size(); i++)
					v[max_ - 1].push_back(v[max_][i]);
				v[max_].clear();
				max_--;
				time += cnt2 * 2;
				b += cnt2;
			}
			else if (max_ == 0) {
				for (ll i = 0; i < v[min_].size(); i++)
					v[min_ + 1].push_back(v[min_][i]);
				v[min_].clear();
				min_++;
				time += cnt;
				b -= cnt;
			}
			else if (cnt <= cnt2 * 2 && b >= cnt) {
				for (ll i = 0; i < v[min_].size(); i++)
					v[min_ + 1].push_back(v[min_][i]);
				v[min_].clear();
				min_++;
				time += cnt;
				b -= cnt;
			}
			else {
				for (ll i = 0; i < v[max_].size(); i++)
					v[max_ - 1].push_back(v[max_][i]);
				v[max_].clear();
				max_--;
				time += cnt2 * 2;
				b += cnt2;
			}
		}
		cout << time << ' ' << min_;
	}