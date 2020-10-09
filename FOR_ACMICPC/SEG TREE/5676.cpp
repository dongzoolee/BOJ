#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
using ll = long long;
ll n, k;
struct segtree {
	vector<pair<ll, ll>>sg;
	ll base;
	void init() {
		for (base = 1; base < n; base *= 2);
		sg.resize(base * 2);
		fill(sg.begin(), sg.end(), make_pair(0, 0));
		ll a;
		for (ll i = base; i < base + n; i++) {
			cin >> a;
			if (a > 0)
				sg[i].first = 1;
			else if (a < 0)
				sg[i].first = -1;
			else
				sg[i].first = 0;

			if (sg[i].first == 0)
				sg[i].second = 1;
		}
		for (ll i = base + n; i < base * 2; i++)
			sg[i].first = -54979;

		for (ll i = base - 1; i >= base / 2; i--) {
			if (sg[i * 2].first == -54979) {
				// 다른 것들에 영향 안주려고
				sg[i].first = 1;
			}
			else if (sg[i * 2 + 1].first == -54979) {
				if (sg[i * 2].second) {
					sg[i].first = 1;
					// 다른 것들에 영향 안주려고
					sg[i].second++;
				}
				else {
					sg[i].first = sg[i * 2].first;
				}
			}
			else {
				if (sg[i * 2].first == 0 && sg[i * 2 + 1].first == 0) {
					sg[i].first = 1, sg[i].second = 2;
				}
				else if (sg[i * 2].first == 0) {
					sg[i].first = sg[i * 2 + 1].first;
					sg[i].second = 1;
				}
				else if (sg[i * 2 + 1].first == 0) {
					sg[i].first = sg[i * 2].first;
					sg[i].second = 1;
				}
				else {
					sg[i].first = sg[i * 2].first * sg[i * 2 + 1].first;
				}
			}
		}

		for (ll i = base / 2 - 1; i > 0; i--) {
			if (sg[i * 2].second && sg[i * 2 + 1].second) {
				sg[i].second += sg[i * 2].second + sg[i * 2 + 1].second;
				// 다른 것들에 영향 안주려고
				sg[i].first = sg[i * 2].first * sg[i * 2 + 1].first;
			}
			else if (sg[i * 2].second) {
				sg[i].second += sg[i * 2].second;
				sg[i].first = sg[i * 2].first * sg[i * 2 + 1].first;
			}
			else if (sg[i * 2 + 1].second) {
				sg[i].second += sg[i * 2 + 1].second;
				sg[i].first = sg[i * 2].first * sg[i * 2 + 1].first;
			}
			else {
				sg[i].first = sg[i * 2].first * sg[i * 2 + 1].first;
			}
		}
	}
	void update(ll a, ll b) {
		a += base - 1;
		if (sg[a].first == 0) {
			if (b) {
				sg[a].first = b;
				sg[a].second = 0;
				for (ll i = a / 2; i > 0; i /= 2) {
					sg[i].second--;
					sg[i].first *= b;
				}
			}
		}
		else {
			if (b) {
				ll tmp = sg[a].first;
				for (ll i = a / 2; i > 0; i /= 2) {
					sg[i].first = sg[i].first / tmp * b;
				}
				sg[a].first = b;
			}
			else {
				sg[a].second = 1;
				for (ll i = a / 2; i > 0; i /= 2) {
					sg[i].first /= sg[a].first;
					sg[i].second++;
				}
				sg[a].first = 0;
			}
		}
	}

	ll mul(ll l, ll r) {
		l += base - 1, r += base - 1;
		ll ret = 1;
		while (l <= r) {
			if (l % 2) {
				if (sg[l].second) return 0;
				ret *= sg[l++].first;
			}
			if (r % 2 == 0) {
				if (sg[r].second) return 0;
				ret *= sg[r--].first;
			}
			l /= 2, r /= 2;
		}
		return ret;
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("i.in.txt", "r", stdin);
	//freopen("outp.txt", "w", stdout);
	while (cin >> n >> k) {
		segtree st;
		st.init();
		char ch;
		ll a, b;
		while (k--) {
			cin >> ch;
			if (ch == 'C') {
				cin >> a >> b;
				st.update(a, b);
			}
			else {
				cin >> a >> b;
				ll ans = st.mul(a, b);
				if (ans == 0)
					cout << 0;
				else if (ans > 0)
					cout << '+';
				else
					cout << '-';
			}
		}
		cout << '\n';
	}
}