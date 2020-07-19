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
int n, m, ans = INT_MAX;
bool chk[10] = { 0 };

int bf() { 
	for (int i = 0;i<499000; i++) {
		//case 1
		int temp = n - i, len;
		if (temp == 0) len = 0; else len = (int)log10(temp);
		if (n - i >= 0)
			for (int f = len; f >= 0; f--) {
				if (chk[temp % 10] == 1) {
					break;
				}
				else {
					temp /= 10;
					if (f == 0) {
						return ans = n - i, 0;
					}
				}
			}
		//case 2
		temp = n + i;
		for (int f = (int)log10(temp); f >= 0; f--) {
			if (chk[temp % 10] == 1) {
				break;
			}
			else {
				temp /= 10;
				if (f == 0) {
					return ans = n + i, 0;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		chk[input] = 1;
	}
	if (m == 10) {
		cout << abs(n - 100);
		return 0;
	}
	else if (m == 0) {
		if (n != 0)
			cout << min(abs(n - 100), (int)log10(n) + 1);
		else
			cout << min(abs(n - 100), 1);
		return 0;
	}
	else
		bf();

	int anslen;
	if (ans == 0) anslen = 1; else anslen = (int)log10(ans) + 1;
	cout << min(abs(n - 100), abs(ans - n) + anslen);
}