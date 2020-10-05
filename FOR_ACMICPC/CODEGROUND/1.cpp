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
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	int n, k;
	cin >> tc;
	int a;
	int date = 1;
	while (tc--) {
		vector<int>va;
		vector<int>vb;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			va.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			cin >> a;
			vb.push_back(a);
		}
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		cout << "Case #" << date++ << '\n';
		cout << max(va[0] + vb[k - 1], vb[0] + va[k - 1]) << '\n';
	}
	return 0;
}