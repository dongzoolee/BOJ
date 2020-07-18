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
ll bunja, bunmo;
ll gcd(ll k, ll l) { return l ? gcd(l, k%l) : k; }

int main() {
	ll dot, open, close;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	while (1) {
		cin >> str;
		if (cin.eof() == 1) return 0;
		ll int_ = 0, notsun = 0, sun = 0;
		// -1을 각각의 분기점으로 하여 vector에 저장
		for (ll i = 0; str[i]; i++) {
			if (str[i] == '.') {
				for (ll f = 0; f < i; f++)
					int_ += (ll)pow(10, i - f - 1)*(str[f] - '0');
				dot = i;
			}
			else if (str[i] == '(') {
				for (ll f = dot + 1; f < i; f++)
					notsun += (ll)pow(10, i - f - 1)*(str[f] - '0');
				open = i;
			}
			else if (str[i] == ')') {
				for (ll f = open + 1; f < i; f++)
					sun += (ll)pow(10, i - f - 1)*(str[f] - '0');
				close = i;
			}
		}

		bunmo = (ll)pow(10, close - dot - 2) - (ll)pow(10, open - dot - 1);
		bunja = int_*(ll)pow(10, close - dot - 2) + notsun * (ll)pow(10, close - open - 1) + sun - ((ll)pow(10, open-dot-1) * int_ + notsun);
		ll gg = gcd(bunja, bunmo);
		cout << str << " = " << bunja/gg << " / " << bunmo/gg << "\n";
	}
	return 0;
}