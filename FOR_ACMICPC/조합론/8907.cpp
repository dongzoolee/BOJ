#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int n, a;
	while (tc--) {
		vector<int>v[1001][2];
		cin >> n;
		for (int i = 1; i < n; i++) {
			for (int f = i + 1; f <= n; f++) {
				cin >> a;
				if (a) {
					v[i][1].push_back(f);
					v[f][1].push_back(i);
				}
				else {
					v[i][0].push_back(f);
					v[f][0].push_back(i);
				}
			}
		}
		int ans = n * (n - 1) * (n - 2) / 6;
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			// 왜 나누기 2입니까??
			// 그려보세요
			tmp += v[i][0].size() * v[i][1].size();
		}
		cout << ans - tmp / 2 << '\n';
	}
}