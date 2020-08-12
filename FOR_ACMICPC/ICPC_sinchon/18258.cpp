#include<queue>
#include<deque>
#include<iostream>
#include<iostream>
using namespace std;
using ll = long long;
deque<int>q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string str;
	int a, frt = 0, bk = -1;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> a;
			q.push_back(a);
			bk++;
		}
		else if (str == "pop") {
			if (bk - frt + 1 > 0)
				cout << q[frt++] << '\n';
			else
				cout << -1 << '\n';
		}
		else if (str == "size") {
			if (bk - frt + 1 >= 0)
				cout << bk - frt + 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "empty") {
			if (bk - frt + 1 > 0) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if (str == "front") {
			if (bk - frt + 1 > 0)
				cout << q[frt] << '\n';
			else
				cout << -1 << '\n';
		}
		else if (str == "back") {
			if (bk - frt + 1 > 0)
				cout << q[bk] << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}