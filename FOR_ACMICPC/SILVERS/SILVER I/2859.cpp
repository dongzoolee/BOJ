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
longs cur[2] = { 0 }, per[2] = { 0 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	for (int t = 0; t < 4; t++) {
		cin >> str;
		if (t <= 1) {
			cur[t] += (str[0] - '0') * 10 * 60;
			cur[t] += (str[1] - '0') * 60;
			cur[t] += (str[3] - '0') * 10;
			cur[t] += (str[4] - '0');
		}
		else {
			per[t-2] += (str[0] - '0') * 10 * 60;
			per[t-2] += (str[1] - '0') * 60;
			per[t-2] += (str[3] - '0') * 10;
			per[t-2] += (str[4] - '0');
		}
	}

	longs a, b, c, d;
	if (cur[0] < cur[1])
		a = 0;
	else
		a = 1;
	b = cur[1 - a] - cur[a];
	for (int i = 1;; i++) {
		if (per[1 - a] == per[a]) { // 별 두개가 안만날 조건 못 찾음 ㅜㅜㅜㅜㅜㅜ
			cout << "Never";
			exit(0);
		}
		if ((b + per[1 - a] * i) % per[a] == 0) {
			c = i;
			d = (b + per[1 - a] * i) / per[a];
			break;
		}
	}
	longs location = cur[1 - a] + per[1 - a] * c, temp = location, cnt = 0, final_h = 0, final_m= 0;
	while (1) {
		if (temp < 1440) {
			final_h = temp / 60;
			final_m = temp % 60;
			break;
		}
		else {
			temp -= 1440;
			cnt++;
		}
	}
	cnt %= 7;
	if (cnt == 0)
		cout << "Saturday\n";
	if (cnt == 1)
		cout << "Sunday\n";
	if (cnt == 2)
		cout << "Monday\n";
	if (cnt == 3)
		cout << "Tuesday\n";
	if (cnt == 4)
		cout << "Wednesday\n";
	if (cnt == 5)
		cout << "Thursday\n";
	if (cnt == 6)
		cout << "Friday\n";

	if (final_h == 0) {
		cout << "00";
	}
	else if ((longs)log10(final_h) + 1 == 1) {
		cout << "0" << final_h;
	}
	else {
		cout << final_h;
	}

	cout << ":";
	if (final_m == 0) {
		cout << "00";
	}
	else if ((longs)log10(final_m) + 1 == 1) {
		cout << "0" << final_m;
	}
	else {
		cout << final_m;
	}
}