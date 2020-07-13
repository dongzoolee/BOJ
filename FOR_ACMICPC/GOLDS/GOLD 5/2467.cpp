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
#include <fstream>
#include <limits.h>
using namespace std;
using ll = long long;
ll arr[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll n;
	cin >> n;
	ll zero_pt = n; // 0이상이 나오는 최초 위치는?
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= 0 && zero_pt == n) {
			zero_pt = i;
		}
	}

	if (zero_pt == n) { // 전부 음수
		cout << arr[n - 2] << " " << arr[n - 1];
	}
	else if (zero_pt == 0) { // 전부 양수
		cout << arr[0] << " " << arr[1];
	}
	else { // 양수 + 음수
		ll idx_h, idx_t, min_ = LLONG_MAX;
		for (ll i = 0; i < zero_pt; i++) {
			ll prv = LLONG_MAX;
			ll lb = lower_bound(arr + zero_pt, arr + n, -arr[i]) - arr;
										// vec.begin()	vec.end() //범위 : [zero_pt, n)
			if (n > lb && lb >=zero_pt) {
				ll ab = abs(arr[lb] + arr[i]);
				if (ab < min_) {
					idx_h = i, idx_t = lb;
					min_ = min(ab, min_);
				}
			}
			if (lb - 1 < n && lb >= zero_pt+1) {
				ll aab = abs(arr[lb - 1] + arr[i]);
				if (aab < min_) {
					min_ = min(min_, aab);
					idx_h = i, idx_t = lb - 1;
				}
			}
		}
		cout << arr[idx_h] << " " << arr[idx_t];
	}
}