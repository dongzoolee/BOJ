#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	ll s = -1000000001, ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (s < v[i].first) s = v[i].first;
		if (v[i].second <= s) continue;
		ans += v[i].second - s; s = v[i].second;
	}
	cout << ans;
}