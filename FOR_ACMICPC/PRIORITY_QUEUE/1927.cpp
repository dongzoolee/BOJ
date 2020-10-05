#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
priority_queue<pair<int, int>>q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	int a;
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (q.size()) {
				cout << -q.top().first * q.top().second << '\n';
				q.pop();
			}
			else
				cout << 0 << '\n';
		}
		else {
			if (a < 0)
				q.push({ a, -1 });
			else
				q.push({ -a,1 });
		}
	}
}