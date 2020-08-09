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
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
stack<int>v[7];
int n, p;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> n >> p;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (v[a].size()) {
			while (v[a].size() && v[a].top() > b) {
				v[a].pop();
				cnt++;
			}
			if (v[a].size() && v[a].top() == b) continue;
			v[a].push(b);
			cnt++;
		}
		else {
			v[a].push(b);
			cnt++;
		}
	}
	cout << cnt;
}