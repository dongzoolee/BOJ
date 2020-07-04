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
using longs = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	longs n, k;
	cin >> n >> k;
	longs arr[] = { 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000 }; // index = 0狼 俺荐

	//n 贸府
	longs temp_ = n, saves = 0;
	for (longs i = 0; i <= 8; i++) {
		if (temp_ - (i+1) * arr[i] <= 0) {
			saves += (i+1) * temp_;
			break;
		}
		else {
			saves += (i+1) * arr[i];
			temp_ -= arr[i];
		}
	}
	if (saves<k) { cout << -1; return 0; }

	//k 贸府
	longs temp = k, save = -1;
	for (longs i = 0; i <= 8; i++) {
		if (temp - arr[i] * (i + 1) <= 0) {
			save = i;
			break;
		}
		else
			temp -= arr[i] * (i + 1);
	}

	if (save == -1)save = 9;
	longs a = temp / (save + 1);
	longs b = temp % (save + 1);

	if (b == 0) {
		cout << (arr[save] / 9 + (a - 1)) % 10;
	}
	else {
		longs front = (arr[save] / 9 + a), ans;
		longs po = (longs)log10(front) + 1;
		for (longs i = 0; i <= po - b; i++) {
			ans =  front % 10;
			front /= 10;
		}
		cout << ans;
	}
}
