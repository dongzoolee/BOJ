#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
int dp[12];

void dpdp(int num) {
	for (int i = 4; i < num + 1; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}

int main() {
	int tc, input;
	cin >> tc;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for (int i = 0; i < tc; i++) {
		cin >> input;
		dpdp(input);
		cout << dp[input] << "\n";
	}
}