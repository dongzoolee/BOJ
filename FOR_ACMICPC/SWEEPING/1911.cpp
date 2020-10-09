#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
using ll = long long;
vector < pair<int, int> > v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	// st = 지금 어디까지 다리 놨는지
	int st = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second - 1 <= st) continue;
		if (st < v[i].first) st = v[i].first;
		else {
			st++;
		}
		if (v[i].second - 1 <= st) continue;
		int cnt = ceil((float)(v[i].second - st) / m);
		st = cnt * m - 1 + v[i].first;
		ans += cnt;
	}
	cout << ans;
}