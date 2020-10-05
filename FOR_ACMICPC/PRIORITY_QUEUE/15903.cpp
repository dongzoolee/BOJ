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
priority_queue<ll, vector<ll>, greater<ll>>q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a;
	for (ll i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	while (m--) {
		ll tmp = 0;
		for (ll i = 0; i < 2; i++) {
			tmp += q.top();
			q.pop();
		}
		for (ll i = 0; i < 2; i++) q.push(tmp);
	}
	ll sz = q.size(),res=0;
	while (sz--) {
		res += q.top();
		q.pop();
	}
	cout << res;
}