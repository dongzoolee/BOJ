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
int n, arr[101], dp[10002] = { 0 };
// dp
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int f = arr[i]; f <= k; f++)
			dp[f] += dp[f - arr[i]]; // arr[i]에 대한 것을 모든 수에 대하여 해주어야
												//	불필요하게 겹치는 수를 제외하여 dp해줄 수 있다.

	cout << dp[k];
}