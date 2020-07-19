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
#include <ctime>
using namespace std;
using ll = long long;
int n = 1, arr[14];
bool chk[14] = { 0 };
void bt(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 14; i++)
			if (chk[i] == 1)
				cout << arr[i] << ' ';
		cout << '\n';
	}

	for (int i = idx; i < n; i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			bt(i + 1, cnt + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);
	while (n != 0) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		bt(0, 0);
		cout << '\n';
	}
}