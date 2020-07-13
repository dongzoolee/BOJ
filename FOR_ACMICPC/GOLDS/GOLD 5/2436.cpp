#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
using ll = long long;
ll gcd(ll k, ll l) { return l ? gcd(l, k % l) : k; }
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll gd, lm, oup1, oup2;
	cin >> gd >> lm;

	ll tmp = lm / gd, tmp2;
	tmp2 = (ll)pow(tmp, 0.5);
	if (tmp2 * tmp2 != tmp) tmp2++;

	for (ll i = 0; tmp2 + i <= tmp; i++) {
		if (tmp % (tmp2 + i) == 0) {
			ll a = tmp / (tmp2 + i) * gd, b = (tmp2 + i) * gd;
			if (gcd(a, b) == gd) {
				cout << a << " " << b;
				break;
			}
		}
	}
	return 0;
}