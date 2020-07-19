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
ll arr[5002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	arr[0] = 1;
	if (str[0] == '0') { cout << "0"; exit(0); }
	else { if (str.length() == 1) { cout << "1"; exit(0); } }

	if ((str[0] - '0') * 10 + str[1] - '0' <= 26) {
		if (str[1] != '0')
			arr[1] = 2;
		else
			arr[1] = 1;
	}
	else {
		if (str[1] != '0')
			arr[1] = 1;
		else {
			cout << "0";
			exit(0);
		}
	}

	for (int i = 2; str[i]; i++) {
		int tst = (str[i - 1] - '0') * 10 + str[i] - '0';
		if (tst == 0) { cout << "0"; exit(0); }

		if (str[i] == '0') {
			if (tst <= 26)
				arr[i] = arr[i - 2] % 1000000;
			else
				arr[i] = 0;
		}
		else if (tst < 10)
			arr[i] = arr[i - 1] % 1000000;
		else if (10 <= tst && tst <= 26)
			arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
		else if (tst > 26)
			arr[i] = arr[i - 1] % 1000000;
	}
	cout << arr[str.length() - 1] % 1000000;
}