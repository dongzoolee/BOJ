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
int arr[21];
bool chk[2000001];
int n, total = 0;

void comb(int idx, int cnt, int sum, int lim) {
	if (cnt == lim) { chk[sum] = 1; return; }

	for (int i = idx; i < n; i++) {
		comb(i + 1, cnt + 1, sum + arr[i], lim);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	//а╤гу
	for (int i = 1; i <= n; i++)
		comb(0, 0, 0, i);

	for (int i = 1;; i++)
		if (chk[i] == 0) {
			cout << i;
			return 0;
		}
}
