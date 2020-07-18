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
ll dp[201][201] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i <= 200; i++) {
		dp[i][1] = 1;
	}

	for (ll h = 2; h <= k; h++) { // °¹¼ö
		for (ll i = 0; i <= n; i++) {
			ll lim;
			if (i % h == 0) lim = i / h;
			else lim = i / h + 1;
			for (ll f = 0; f <= i; f++) { // ÀÌ´Ï¼È numb
				dp[i][h] += dp[f][h - 1];
			}
			dp[i][h] %= 1000000000;
		}
	}
	cout << dp[n][k];
}