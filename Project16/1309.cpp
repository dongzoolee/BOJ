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
ll dp[100001] = { 0 }, output = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n == 1) { cout << 3; return 0; }
	if (n == 2) { cout << 7; return 0; }
	dp[0] = 3, dp[1] = 7;

	for (ll i = 3; i <= n; i++) {
		dp[2] = (dp[1] - 2 * (i-1) - 1+ 2 * (dp[0] - 1) + (dp[1] - 3) - (dp[0] - 1) + 1 + i * 2 + 2) % 9901;

		// 배열 복사
		dp[0] = dp[1];
		dp[1] = dp[2];
	}

	cout << dp[2];
	return 0;
}