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
vector<int>v;
int cnt[1001] = { 0 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, inp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}

	for (int i = v.size()-1; i >= 0; i--) {
		if (cnt[v[i]] == 0)
			cnt[v[i]] = 1;
		for (int f = i; f >= 0; f--) {
			if (v[i] > v[f])
				cnt[v[f]] = max(cnt[v[i]] + 1, cnt[v[f]]);
		}
	}

	cout << *max_element(cnt, cnt + 1001);
	return 0;
}