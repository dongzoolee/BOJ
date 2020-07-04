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
int arr[5][5], n, m, k, counter = 0;

void bt(int cnt, int a, int b, vector<int> v) {
	if (a < 0 || a >= n) return;
	if (b < 0 || b >= m) return;
	if (arr[a][b] == 1) return;
	if (cnt == k) {
		if (a == 0 && b == m - 1)
			counter++;
		else
			return;
	}

	if (find(v.begin(), v.end(), (a + 1) * m + b + 1) == v.end()) {
		v.push_back((a + 1) * m + b + 1);
		bt(cnt + 1, a + 1, b, v);
		v.pop_back();
	}
	if (find(v.begin(), v.end(), a * m + b + 2) == v.end()) {
		v.push_back(a * m + b + 2);
		bt(cnt + 1, a, b + 1, v);
		v.pop_back();
	}
	if (find(v.begin(), v.end(), (a - 1) * m + b + 1) == v.end()) {
		v.push_back((a - 1) * m + b + 1);
		bt(cnt + 1, a - 1, b, v);
		v.pop_back();
	}

	if (find(v.begin(), v.end(), a * m + b) == v.end()) {
		v.push_back(a * m + b);
		bt(cnt + 1, a, b - 1, v);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char ch;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			cin >> ch;
			if (ch == '.')
				arr[i][f] = 0;
			else
				arr[i][f] = 1;
		}
	vector<int>vec;
	vec.push_back(m * (n - 1) + 1);
	bt(1, n - 1, 0, vec);
	cout << counter;
}