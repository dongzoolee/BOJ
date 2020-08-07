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
int arr[1001];
int dp1[1001] = { 0 };
int dp2[1001] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	bool chk = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (dp1[i] == 0)
			dp1[i] = 1;
		for (int f = i + 1; f < n; f++) {
			if (arr[i] < arr[f])
				dp1[f] = max(dp1[i] + 1, dp1[f]);
		}
	}
	for (int i = n - 1; i > 0; i--) {
		if (dp2[i] == 0)
			dp2[i] = 1;
		for (int f = i - 1; f >= 0; f--) {
			if (arr[i] < arr[f])
				dp2[f] = max(dp2[i] + 1, dp2[f]);
		}
	}
	for (int i = 0; i < n; i++)
		dp1[i] = dp1[i] + dp2[i];

	int mx = *max_element(dp1, dp1 + n);
	if (mx > 1)
		cout << mx - 1;
	else
		cout << 1;
}