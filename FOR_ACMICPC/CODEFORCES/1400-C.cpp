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
vector<int>v;
int no = 0;
void come(string str, int x) {
	int slen = str.length();
	v.resize(slen);
	fill(v.begin(), v.end(), -1);
	for (int i = 0; i < x; i++) {
		if (str[i] == '1') {
			if (i + x < slen)
				v[i + x] = 1;
		}
		else {
			if (i + x < slen)
				v[i + x] = 0;
		}
	}
	for (int i = slen - x; i < slen; i++) {
		if (str[i] == '1') {
			if (i - x >= 0 && v[i - x] == 0) {
				no = -1;
				return;
			}
			else if (i - x >= 0 && v[i - x] == -1) {
				v[i - x] = 1;
			}
		}
		else {
			if (i - x >= 0 && v[i - x] == 1) {
				no = -1;
				return;
			}
			else if (i - x >= 0 && v[i - x] == -1) {
				v[i - x] = 0;
			}
		}
	}
	if (slen - 2 * x > 1)
		for (int i = x; i < slen - 2 * x; i++) {
			if (str[i] == '1') {
				if (v[i - x] == 0) {
					no = -1;
					return;
				}
				else
					v[i - x] = 1;
			}
			else {
				if (v[i - x] == 1) {
					no = -1;
					return;
				}
				else
					v[i - x] = 0;
			}
		}
	if (slen - 2 * x >= 0)
		for (int i = slen - 2 * x; i < slen - x; i++) {
			if (str[i] == '1') {
				if ((i - x >= 0 && v[i - x] == 0) && (i + x < slen && v[i + x] == 0)) {
					no = -1;
					return;
				}
				else {
					if (i - x >= 0)
						v[i - x] = 1;
					if (i + x < slen)
						v[i + x] = 1;
				}
			}
			else {
				if ((i - x >= 0 && v[i - x] == 1) || (i + x < slen && v[i + x] == 1)) {
					no = -1;
					return;
				}
				else {
					if (i - x >= 0)
						v[i - x] = 0;
					if (i + x < slen)
						v[i + x] = 0;
				}
			}
		}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	string str;
	int x;
	while (tc--) {
		cin >> str >> x;
		come(str, x);
		if (no == -1)
			cout << -1;
		else
			for (int i = 0; i < v.size(); i++)
				if (v[i] == -1)
					cout << 0;
				else
					cout << v[i];
		cout << '\n';
		no = 0;
		v.clear();
	}
}