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
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, tc;
	cin >> tc;
	for (ll i = 0; i < tc; i++) {
		ll cnt = 0, arr[100002];
		bool chk[100002] = { 0 };
		cin >> n;
		for (ll f = 1; f <= n; f++)
			cin >> arr[f];

		for (ll i = 1; i <= n; i++) {
			if (i == arr[i]) { cnt++; continue; }
			if (chk[i] == 0) {
				ll st = i, cur = i, tmp_cnt = 0;
				while (chk[cur] == 0) {
					chk[cur] = 1;
					cur = arr[cur];
					tmp_cnt++;
				}
				if (cur == st) {
					cnt += tmp_cnt;
				}
			}
		}
		cout << n - cnt << '\n';
	}

}