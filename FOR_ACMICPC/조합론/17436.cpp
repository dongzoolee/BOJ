#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
ll arr[10], ans;
ll a, b;
vector<ll>v;
void bt(ll cur, ll cnt) {
	if (cnt == 0) {
		ll mul = 1;
		for (ll i = 0; i < v.size(); i++) {
			mul *= v[i];
		}
		if (v.size() % 2) {
			ans += b / mul;
		}
		else {
			ans -= b / mul;
		}
		return;
	}
	for (ll i = cur + 1; i < a; i++) {
		v.push_back(arr[i]);
		bt(i, cnt - 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	for (ll i = 0; i < a; i++)	cin >> arr[i];

	for (ll i = 1; i <= a; i++) {
		bt(-1, i);
	}
	cout << ans;
}