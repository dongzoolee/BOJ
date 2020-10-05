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
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
priority_queue < int, vector<int>, greater<int>>ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		q.push({ b,a }); // 레벨 / 선호도
	}
	int lv, sum = 0, tmp = n;
	while (tmp--) {
		ans.push(q.top().second);
		sum += q.top().second;
		lv = q.top().first;
		q.pop();
	}
	for(int i = n;i<k && sum<m;i++) {
		lv = q.top().first;
		sum += q.top().second;
		sum -= ans.top();
		ans.pop();
		ans.push(q.top().second);
		q.pop();
	}
	if (sum >= m)
		cout << lv;
	else
		cout << -1;
}