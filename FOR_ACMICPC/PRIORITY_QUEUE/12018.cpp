#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
priority_queue<int, vector<int>, greater<int>>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		cin >> a >> b;
						// 잔액이 있다면......
		if (a < b) { if (m) { m--; cnt++; for (int f = 0; f < a; f++) cin >> c; } }
		else {
			for (int f = 0; f < a; f++) {
				cin >> c;
				tmp.push_back(c);
			}
			sort(tmp.begin(), tmp.end(),greater<>());
			v.push(tmp[b - 1]);
		}
	}
	while (v.size() && v.top() <= m) {
		m -= v.top();
		v.pop();
		cnt++;
	}
	cout << cnt;
}