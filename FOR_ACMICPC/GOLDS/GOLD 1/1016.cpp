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
	bool chk[1000001] = { 0 };
	ll ans = 0;
	int main() {
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		ll n, m;
		cin >> n >> m;
		ll cnt = 0;
		ll sqt = sqrt(m);
		for (ll i = 2; i <= sqt ; i++) {
			ll exp = i * i;
			if (exp > m) break;
			ll togo = n / exp * exp;
			if (togo < n) togo += exp;
			if (togo > m) continue;
			chk[togo - n] = 1;
			while (togo + exp <= m) {
				togo += exp;
				chk[togo - n] = 1;
			}
		}
		for (int i = 0; i <= m - n; i++)
			if (chk[i])
				cnt++;
		cout << m - n + 1 - cnt;
	}