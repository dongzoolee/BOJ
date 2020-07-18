#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <limits.h>
using namespace std;
using ll = long long;
ll arr[2], tens[10] = { 1,10,100,1000,10000,100000,1000000 };

void bfs(ll m) {
	string dp[10001] = { "" };
	bool chk[10001] = { 0 };
	ll len;

	ll cnt = 0;
	queue<ll>q;
	q.push(m);
	chk[m] = 1;

	while (!q.empty()) {
		ll q_size = q.size();
		for (ll i = 0; i < q_size; i++) {
			ll frt = q.front();
			if (frt != 0)
				len = (ll)log10(frt) + 1;
			else
				len = 1;
			q.pop();

			if (frt * 2 <= 9999) {
				if (chk[frt * 2] == 0) {
					q.push(frt * 2);
					chk[frt * 2] = 1;
					dp[frt * 2] = dp[frt] + "D";
				}
			}
			else {
				ll mod = frt * 2 % 10000;
				if (chk[mod] == 0) {
					q.push(mod);
					chk[mod] = 1;
					dp[mod] = dp[frt] + "D";
				}
			}

			if (frt != 0) {
				if (chk[frt - 1] == 0) {
					q.push(frt - 1);
					chk[frt - 1] = 1;
					dp[frt - 1] = dp[frt] + "S";
				}
			}
			else {
				if (chk[9999] == 0) {
					q.push(9999);
					chk[9999] = 1;
					dp[9999] = dp[frt] + "S";
				}
			}

			ll tst = (frt % 1000) * 10 + frt / 1000;
			if (chk[tst] == 0) {
				q.push(tst);
				chk[tst] = 1;
				dp[tst] = dp[frt] + "L";
			}

			ll ts = (frt % 10) * 1000 + (frt / 10);
			if (chk[ts] == 0) {
				q.push(ts);
				chk[ts] = 1;
				dp[ts] = dp[frt] + "R";
			}

			if (frt == arr[1]) {
				cout << dp[frt];
				return;
			}
		} // end of for
	} // end of while
}
int main() {
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		cin >> arr[0] >> arr[1];
		bfs(arr[0]);
		cout << '\n';
	}
}