#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
int arr[3000][3];
vector<int>par;
int n;
int find(int a) {
	if (a == par[a]) return a;

	return par[a] = find(par[a]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (a > b) swap(a, b);
	par[b] = a;
}
void init() {
	for (int i = 0; i < n; i++)
		par[i] = i;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		//memset(chk, 0, sizeof(chk)); v
		par.resize(n);
		init();
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}

		for (int i = 0; i < n - 1; i++)
			for (int f = i + 1; f < n; f++) {
				int x = arr[i][0] - arr[f][0], y = arr[i][1] - arr[f][1], r = arr[i][2] + arr[f][2];
				if (x * x + y * y <= r * r) {
					unite(i, f);
				}
			}

		/*int ret = 0;
		for (int i = 0; i < n; i++) {
			if (!chk[par[i]]) {
				chk[par[i]] = 1;
				ret++;
			}
		}
		cout << ret<<'\n';*/
		sort(par.begin(), par.end());
		cout << unique(par.begin(), par.end()) - par.begin() << '\n';
	}
}