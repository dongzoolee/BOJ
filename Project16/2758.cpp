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
ll cnt = 0, tc, n, m;

void bt(ll idx, vector<ll>v) {
	cnt += m - v[n - 1] + 1;
	if (idx == 0) return;

		while (++v[idx - 1] <= m && idx > 0) {
			for (ll i = idx; i < n; i++) {
				v[i] = v[i - 1] * 2;
				if (v[i] > m) return;
			}
			bt(idx - 1, v);
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> tc;
	for (ll i = 0; i < tc; i++) {
		vector<ll>v;
		cin >> n >> m;
		for (ll i = 0; i < n; i++)
			v.push_back((ll)pow(2, i));
		if (v[n - 1] <= m) {
			cnt = 0; bt(n - 1, v);
			cout << cnt << "\n";
		}
		else
			cout << 0 << "\n";
	}
}