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
#include <ctime>
using namespace std;
using ll = long long;
ll arr[100];
ll dp[100][21] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	dp[0][arr[0]] = 1;
	for (ll f = 1; f < n-1; f++)
		for (ll i = 0; i <= 20; i++) {
			if (dp[f - 1][i] != 0) {
				if (arr[f] + i <= 20) {
					dp[f][arr[f] + i] += dp[f - 1][i];
				}
				if (i - arr[f] >= 0) {
					dp[f][i - arr[f]] += dp[f - 1][i];
				}
			}
		}

	//for(ll i = 0;i<=20;i++)
	cout << dp[n - 2][arr[n - 1]];
}