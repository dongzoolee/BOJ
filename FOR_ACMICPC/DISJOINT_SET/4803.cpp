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
int par[501];
int chk[501] = { 0 };
int n, m;
int find(int a) {
	if (a == par[a]) return a;

	return par[a] = find(par[a]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b || chk[a] == -1 || chk[b] == -1) {
		chk[a] = -1;
		chk[b] = -1;
		return;
	}

	if (a > b) swap(a, b);
	par[b] = a;
}
void init() {
	for (int i = 1; i <= n; i++)
		par[i] = i;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, idx = 0;
	while (1) {
		cin >> n >> m;
		init();
		if (n + m == 0) break;
		while (m--) {
			cin >> a >> b;
			unite(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = find(i);
			if (chk[tmp] == 0) {
				chk[tmp] = 1;
				ans++;
			}
		}
		cout << "Case " << ++idx << ": ";
		if (ans == 0) {
			cout << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << ans << " trees.\n";
		}
		memset(chk, 0, sizeof(chk));
	}
}