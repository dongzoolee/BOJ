#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll l = 1;
	ll r = n * n;
	ll mid = (l + r) / 2;
	ll ret = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);

		if (cnt < k) {
			l = mid + 1;
		}
		else {
			ret = mid;
			r = mid - 1;
		}
	}
	cout << ret;
}