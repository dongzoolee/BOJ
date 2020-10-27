#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll x, y;
	cin >> x >> y;
	ll z = y * 100 / x;
	// cout << z;
	/*for (ll i = 0;; i++) {
		ll tmp = floor((float(y) + i) / (x + i) * 100);
		if (tmp != z) {
			cout << i;
			break;
		}
	}*/
	ll st = 1;
	ll end = 1'000'000'000;
	ll mid = (st + end) / 2;
	ll ret = 0;
	while (st <= end) {
		mid = (st + end) / 2;
		ll tmp = (y + mid) * 100 / (x + mid);
		if (tmp >= z + 1) {
			ret = mid;
			end = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	if (ret != 0)
		cout << ret;
	else
		cout << -1;
}