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
int arr[100], n, m, max_ = 0;

void bt(int idx, int sum, int cnt) {
	if (cnt == 3) {
		if (sum <= m)
			max_ = max(sum, max_);
		return;
	}

	for (int i = idx; i < n; i++)
		bt(i + 1, sum + arr[i], cnt + 1);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bt(0, 0, 0);
	cout << max_;
}