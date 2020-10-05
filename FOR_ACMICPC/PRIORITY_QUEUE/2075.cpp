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
#include <deque>
#include <numeric>
using namespace std;
using ll = long long;
priority_queue<int, vector<int>, greater<int>>q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < n; f++) {
			cin >> a;
			q.push(a);
			if (q.size() == n+1)
				q.pop();
		}
	cout << q.top();
}