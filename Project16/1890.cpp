#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, arr[101][101], dp[101][101] = { 0 };

void ddp(ll m) {
	for (ll i = 0; i < n; i++)
		for (ll f = 0; f < n; f++) {
			if (arr[i][f] != 0) {
				if (i == 0 && f == 0) {
					if (arr[i][f] + i < n)
						dp[i + arr[i][f]][f]++;
					if (arr[i][f] + f < n)
						dp[i][f + arr[i][f]]++;
				}
				else {
					if (arr[i][f] + i < n)
						dp[i + arr[i][f]][f] += dp[i][f];
					if (arr[i][f] + f < n)
						dp[i][f + arr[i][f]] += dp[i][f];
				}
			}
		}
}

int main() {
	cin >> n;
	for (ll i = 0; i < n; i++)
		for (ll f = 0; f < n; f++)
			cin >> arr[i][f];

	ddp(0);
	cout << dp[n - 1][n - 1];
}