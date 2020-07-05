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
	ll n;
	string str;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll dot = 1, open = -1, close = -1, bunja = 0, bunmo = 0;
		cin >> str;
		for (ll f = 0; f < str.length(); f++) {
			if (str[f] == '(')
				open = f;
			if (str[f] == ')')
				close = f;
		}

		// �ϹݼҼ�o ��ȯ�Ҽ� x
		if (open == -1 && close == -1) {
			for (ll i = 2; i < str.length(); i++)
				bunja += (ll)pow(10, str.length() - i - 1) * (str[i] - '0');
			bunmo = (ll)pow(10, str.length() - 2);
		}
		// �ϹݼҼ�o ��ȯ�Ҽ� o
		else if (open != 2) {
			bunmo = (ll)pow(10, close - dot - 2) - (ll)pow(10, open - dot - 1);
			// �ϹݼҼ�
			for (ll i = 2; i < open; i++)
				bunja += (ll)pow(10, close - i - 2) * (str[i] - '0');
			// ��ȯ�Ҽ�
			for (ll i = open + 1; i < close; i++)
				bunja += (ll)pow(10, close - i - 1) * (str[i] - '0');
			// ��ȯ�Ҽ� ����
			for (ll i = dot + 1; i < open; i++)
				bunja -= (ll)pow(10, open - i - 1) * (str[i] - '0');
		}
		// �ϹݼҼ�x ��ȯ�Ҽ� o
		else {
			bunmo = (ll)pow(10, close - open - 1) - 1;
			for (ll i = 3; i < close; i++)
				bunja += (ll)pow(10, close - i - 1) * (str[i] - '0');
		}
		ll gg = gcd(bunja, bunmo);
		cout << bunja / gg << "/" << bunmo / gg << "\n";
	}
}