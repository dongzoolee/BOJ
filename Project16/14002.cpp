#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <ctime>
#include <tuple>
#include <array>
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
vector<int>v;
vector<int>vec[1000];
int dp[1000] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, inp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}

	dp[n - 1] = 1;
	vec[n - 1].push_back(v[n - 1]);
	for (int i = n - 1; i >= 0; i--) {
		for (int f = i; f >= 0; f--) {
			if (dp[i] == 0) {
				vec[i].push_back(v[i]);
				dp[i] = 1;
			}
			if (v[i] > v[f])
				if (dp[f] < dp[i] + 1) {
					dp[f] = dp[i] + 1;
					vec[f] = vec[i];
					vec[f].push_back(v[f]);
				}
		}
				
	}
	int mx = *max_element(dp, dp + n), idx;
	cout << mx << '\n';
	for (int i = 0; i < n; i++) if (vec[i].size() == mx) idx = i;
	for (int i = vec[idx].size() - 1; i >= 0; i--)
		cout << vec[idx][i] << ' ';

}