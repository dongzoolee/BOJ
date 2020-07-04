#include <iostream>
#include <stdio.h>
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
long long arr[100001];
long long dp[100001] = { 0 };

int main() {
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	long long max_ = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		max_ = max(max_, dp[i]);
	}
	cout << max_;
}