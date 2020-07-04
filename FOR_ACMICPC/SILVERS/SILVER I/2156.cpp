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
int arr[1001], n, max_ = 0;

void bt(int cont, int cur, int sum) {
	if (cur >= n - 1) {
		max_ = max(max_, sum);
		return;
	}
	sum += arr[cur];
	if (cont == 1) {
		bt(2, cur + 1, sum);
		bt(2, cur + 2, sum);
	}
	else if (cont == 2) {
		bt(1, cur + 2, sum);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	bt(1, 0, 0);
	bt(1, 1, 0);
	bt(1, 2, 0);
	cout << max_;
}