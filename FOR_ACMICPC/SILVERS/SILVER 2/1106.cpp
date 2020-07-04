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
vector <pair<int, int>> vec;

int main() {
	int goal_sum, tc, price, room, dp[1111] = { 0 }, real_min = INT_MAX;
	cin >> goal_sum >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> price >> room;
		vec.push_back({ price, room });
		dp[room] = price;
	}
	sort(begin(vec), end(vec), [](auto a, auto b) {
		return a.second < b.second; });

	//DP
	for (int i = vec[0].second;; i++) {
		if (dp[i] == 0)
			for (int f = 0; f < tc && vec[f].second <= i; f++) {
				if (dp[i - vec[f].second] != 0) {
					if (f == 0)
						dp[i] = dp[i - vec[f].second] + vec[f].first;
					dp[i] = min(dp[i - vec[f].second] + vec[f].first, dp[i] + vec[f].first);
				}
			}
		real_min = min(dp[i], real_min);
	}
	cout << real_min;
}