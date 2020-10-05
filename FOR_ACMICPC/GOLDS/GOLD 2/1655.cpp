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

<int>maxh;
priority_queue<int>minh;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (i % 2)
			maxh.push(a);
		else
			minh.push(-a);
		if (i >= 2)
			if (maxh.top() > -minh.top()) {
				int mn = maxh.top(), mx = -minh.top();
				maxh.pop(), minh.pop();
				maxh.push(mx), minh.push(-mn);
			}
		cout << maxh.top() << '\n';
	}
}