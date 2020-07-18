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
bool chk[9] = { 0 };
int n, m;
void bt(int st, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < 9; i++)
			if (chk[i] == 1)
				cout << i << ' ';
		cout << '\n'; return;
	}

	for (int i = st; i <= n; i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			bt(i + 1, cnt + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	bt(1, 0);
}