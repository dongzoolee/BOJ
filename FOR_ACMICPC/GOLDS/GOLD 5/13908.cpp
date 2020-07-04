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
using longs = long long;
longs arr[8], n, k, counter = 0;
longs fact[11];

void dd(int k, int i) {
	longs temp = 0, dp[10] = { 0 };
	for (int f = 1; f < k; f++) {
		dp[f] = (longs)pow(f, i) * (fact[k] / fact[k - f] / fact[f]);
		for (int h = f - 1; h > 0; h--)
			dp[f] -= dp[h] * (fact[k - h] / fact[k - f] / fact[f - h]);
		temp += dp[f];
	}
	counter += (fact[n] / fact[i] / fact[n - i]) * ((longs)pow(k, i) - temp) * (longs)pow(10 - k, n - i);
}

int main() {
	fact[0] = 1;
	for (int i = 1; i <= 10; i++)
		fact[i] = i * fact[i - 1];

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	// 안겹치는 경우
	counter += fact[n] / fact[n - k] * (longs)pow((10 - k), n - k);
	// 겹치는 경우
	for (int i = k + 1; i <= n; i++) {
		dd(k, i);
	}
	cout << counter;
}