#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<limits.h>
#include<string>
using namespace std;
using ll = long long;
vector<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	// -99 -2 -1 4 98
	int min_ = INT_MAX;
	int ans1, ans2;
	for (int i = 0; i < n; i++) {
		auto a = lower_bound(v.begin(), v.end(), -v[i]);
		//auto b = *a;
		int idx = a - v.begin();
		if (idx - 1 >= 0 && idx - 1 != i) {
			if (abs(min_) > abs(v[i] + v[idx - 1])) {
				min_ = v[i] + v[idx - 1];
				ans1 = v[i], ans2 = v[idx - 1];
			}
		}
		if (idx < n && idx != i) {
			if (abs(min_) > abs(v[i] + v[idx])) {
				min_ = v[i] + v[idx];
				ans1 = v[i], ans2 = v[idx];
			}
		}
		if (idx + 1 < n && idx + 1 != i) {
			if (abs(min_) > abs(v[i] + v[idx + 1])) {
				min_ = v[i] + v[idx + 1];
				ans1 = v[i], ans2 = v[idx + 1];
			}
		}
	}
	if (ans1 > ans2)
		swap(ans1, ans2);
	cout << ans1 << ' ' << ans2;
}