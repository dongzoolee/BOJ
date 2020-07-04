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
longs n, counter = 0, dp[10] = { 0 };
vector<longs> v(2, 0);

void dfs(longs cur, vector<longs>vec) {
	if (n != cur) {
		longs temp = vec[0];
		vec[0] = vec[1] + vec[0];
		vec[1] = temp;
		dfs(cur + 1, vec);
	}
	else {
		cout << vec[0] + vec[1];
		exit(0);
	}
}
int main() {
	cin >> n;
	dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 3;
	if (n > 4) {
		v[0] += 2;
		v[1]++;
		dfs(4, v);
	}
	else {
		cout << dp[n];
	}
}