#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
using ll = long long;
vector<ll>x;
vector<ll>y;
int main() {
	ll n, m;
	cin >> n >> m;
	ll a, b, tmp = m;
	while (m--) {
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int xmid, ymid;
	if (tmp % 2) {
		xmid = x[tmp / 2];
		ymid = y[tmp / 2];
	}
	else {
		xmid = (x[tmp / 2 - 1] + x[tmp / 2]) / 2;
		ymid = (y[tmp / 2 - 1] + y[tmp / 2]) / 2;
	}
	ll ans = 0;
	for (ll i = 0; i < tmp; i++) {
		ans += abs(xmid - x[i]) + abs(ymid - y[i]);
	}
	cout << ans;
}