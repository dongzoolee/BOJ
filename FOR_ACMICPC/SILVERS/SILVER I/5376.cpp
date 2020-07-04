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
	int n, dot = 1, open = -1, close = -1, bunja = 0, bunmo = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int f = 0; f < str.length(); f++) {
			if (str[f] == '(')
				open = i;
			if (str[f] == ')')
				close = i;
		}

		// 일반소수o 순환소수 x
		if (open == -1 && close == -1) {
			for (int i = 2; i < str.length(); i++)
				bunja += (int)pow(10, str.length() - i - 1) * (str[i] - '0');
			bunmo = (int)pow(10, str.length() - 2);
			int gg = gcd(bunja, bunmo);
			cout << bunja / gg << "/" << bunmo / gg << "\n";
		}
		// 일반소수o 순환소수 o
		else if (open != 2) {

		}
			// 일반소수x 순환소수 o
		else {

		}
	}


}