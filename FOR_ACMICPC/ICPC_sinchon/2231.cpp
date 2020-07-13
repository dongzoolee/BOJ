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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int nlen = (int)log10(n) + 1;

	for (int i = n - nlen * 9; i < n; i++) {
		int temp = i, save = 0;
		while (temp != 0) {
			save += temp % 10;
			temp /= 10;
		}
		if (save + i == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}