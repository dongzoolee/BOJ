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
#include <ctime>
using namespace std;
using ll = long long;
vector<pair<int, int>>v;
int dp[100000] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, inp1,inp2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> inp1 >> inp2;
		v.push_back({ inp1,inp2 });
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.first < b.first;
	});

	dp[v[0].first] = v[0].second;
	for (int i = 1; i < n; i++) {
		for (int f = 0; f < i; f++)
			dp[v[i].first] += dp[v[i].first - v[f].first];
	}

	cout << dp[k];
}