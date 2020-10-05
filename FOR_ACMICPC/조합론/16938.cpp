#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
vector<int>v;
int n, l, r, x, a;
int cnt, tmp;
void bt(int num, int a, int b, int cur, int sum) {
	if (num == 0) {
		if (l <= sum && sum <= r)
			cnt++;
	}

	for (int i = cur + 1; i < b; i++) {
		sum += v[i];
		bt(num - 1, a, b, i, sum);
		sum -= v[i];
	}
}
void cal(int a, int b) {
	int sum = 0;
	sum = v[a] + v[b];
	if (l <= sum && sum <= r) {
		cnt++;
	}
	else if (sum > r) {
		return;
	}
	for (int i = 1; i <= b - a - 1; i++) {
		bt(i, a, b, a, sum);
	}

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++)
		for (int f = i + 1; f < n; f++) {
			if (v[f] - v[i] >= x) {
				cal(i, f);
			}
		}
	cout << cnt;
}