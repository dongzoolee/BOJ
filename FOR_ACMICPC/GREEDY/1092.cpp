#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
using ll = long long;
deque<int>limit;
deque<int>box;
int n, m, time = 0;
void judge() {
	int ldx = 0, cnt = 0;
	for (deque<int>::iterator it = box.begin(); it != box.end();) {
		if (*it <= limit[ldx]) {
			it = box.erase(it, it + 1);
			cnt++, ldx++;
			if (cnt == limit.size()) {
				break;
			}
		}
		else {
			++it;
		}
	}

	if (box.size() && cnt) {
		time++;
		return judge();
	}
	else if (box.size() && cnt == 0) {
		cout << -1;
		exit(0);
	}
	else {
		cout << ++time;
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) { cin >> a; limit.push_back(a); }
	sort(limit.begin(), limit.end(), greater<>());
	cin >> m;
	for (int i = 0; i < m; i++) { cin >> a; box.push_back(a); }
	sort(box.begin(), box.end(), greater<>());
	judge();
}