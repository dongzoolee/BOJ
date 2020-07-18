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
int cent[4] = { 1,5,10,25 }, a[4], max_ = 0, xx, dp[10001][5] = { 0 };

int main() {
	vector<int> vec(4, 0);
	cin >> xx >> a[0] >> a[1] >> a[2] >> a[3];
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;

	for (int i = 1; i <= xx; i++) {
	//	dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;
		dp[i][4] = -1;
		for (int f = 0; f < 4; f++) {
			if (i - cent[f] >= 0) {
				if (dp[i - cent[f]][4] > dp[i][4]) {
					if (dp[i - cent[f]][f] + 1 > a[f]) continue;
					dp[i][f] = dp[i - cent[f]][f] + 1;
					dp[i][4] = dp[i - cent[f]][4] + 1;
					for (int h = 0; h < 4; h++)
						if (h != f)
							dp[i][h] = dp[i - cent[f]][h];
				}
			}
		}
	}
	cout << dp[xx][0] << " " << dp[xx][1] << " " << dp[xx][2] << " " << dp[xx][3];
}