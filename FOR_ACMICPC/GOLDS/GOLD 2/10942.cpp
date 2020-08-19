#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
using ll = long long;
deque<int>q;
int n, m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push_back(a);
	}
	cin >> m;
	int ret = 1;
	while (m--) {
		ret = 1;
		cin >> a >> b;
		a--, b--;
		while (a < b) {
			if (q[a++] != q[b--]) {
				ret = 0;
				break;
			}
		}
		cout << ret << '\n';
	}
}